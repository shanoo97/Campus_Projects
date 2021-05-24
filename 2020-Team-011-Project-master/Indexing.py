import xml.etree.ElementTree as ET
import csv
import pickle
import multiprocessing

# Number of Threads can be changed here
Numbofthreads = 2

# Setting up variables
manager = multiprocessing.Manager()
data = manager.list()
headings_hash_table = manager.dict()
names_hash_table = manager.dict()
bitmap_index = manager.list()
bitmap_index.append([0])

# Creating barriers that are required
b = multiprocessing.Barrier(Numbofthreads)
newb = multiprocessing.Barrier(Numbofthreads)


# Function to Strip punctuation and convert it to lower
def strip(s):
    punctuation = "!@#$%^'&*()_+<>?:.,;"
    for c in s:
        if c in punctuation:
            s = s.replace(c, "")
    return s.lower()


# Parse Tree
tree = ET.parse('Hansard.xml')
akoma = tree.getroot()


# Function to extract data from tree
def retrieve_data(start, end):
    temp = []
    for i in range(start, end):
        for elem in akoma[0][3][i].findall(".//{http://docs.oasis-open.org/legaldocml/ns/akn/3.0}debateSection"):
            for name in elem:
                if "heading" in name.tag:
                    heading = name.text.encode().decode('ascii', errors='ignore')
                if "speech" in name.tag:
                    if len(name[0]):
                        temp.append(strip(name[0][0].text.encode().decode('ascii', errors='ignore')))
            data.append([strip(heading), temp])
            temp = []


# The main function used by all threads
def run(threadID):
    size = int(len(akoma[0][3]) / Numbofthreads)
    start = threadID * size
    end = threadID * size + size
    if threadID == Numbofthreads - 1:
        end = len(akoma[0][3])

    retrieve_data(start, end)
    b.wait()

    size = int(len(data) / Numbofthreads)
    start = threadID * size
    end = threadID * size + size
    if threadID == Numbofthreads - 1:
        end = len(data)

    create_hash(data[start:end])

    bitmap(data[start:end])


# Creating bitmap
def bitmap(input):
    add_names_debates(input)
    newb.wait()

    for row in input:
        pos = add_zeros(row)
        add_ones(row, pos)


def add_names_debates(input):
    for row in input:
        if [row[0]] not in bitmap_index:
            bitmap_index.append([row[0]])
        for element in row[1]:
            if element not in bitmap_index[0]:
                tmp = bitmap_index[0]
                tmp.append(element)
                bitmap_index[0] = tmp


# append zeros to row
def add_zeros(row):
    for i in range(len(bitmap_index)):
        if bitmap_index[i][0] == row[0]:
            pos = i
            tmp = bitmap_index[pos]
            while len(tmp) != len(bitmap_index[0]):
                tmp.append(0)
            bitmap_index[pos] = tmp
            break
    return pos


# Change values to 1 from bitmap
def add_ones(row, pos):
    tmp = bitmap_index[pos]
    for index, element in enumerate(bitmap_index[0][1:]):
        if element in row[1]:
            tmp[index + 1] = 1
    bitmap_index[pos] = tmp


# Insert into hash map
def insert(hash_table, key, value):
    key = hash_djb2(key)
    if key not in hash_table:
        hash_table[key] = [value]
    else:
        temp = hash_table[key]
        if value not in temp:
            temp.append(value)
            hash_table[key] = temp


# Creates hash table
def create_hash(input):
    for row in input:
        insert(headings_hash_table, row[0], row[0])
        for element in row[1]:
            insert(names_hash_table, element, element)


# Hash function used to hash values
def hash_djb2(s):
    hash = 5381
    for x in s:
        hash = ((hash << 5) + hash) + ord(x)
    return hash % 100


if __name__ == '__main__':

    threads = []

    for i in range(0, Numbofthreads):
        p = multiprocessing.Process(target=run, args=(i,))
        # threads.append(myThread(i,"Thread-"+str(i)))
        threads.append(p)
        p.start()

    for p in threads:
        p.join()

    names = {}
    headings = {}

    # Converting manager data structures to normal python data structures
    for elem in names_hash_table.keys():
        names[elem] = names_hash_table[elem]

    for elem in headings_hash_table.keys():
        headings[elem] = headings_hash_table[elem]

    # Writing to csv to easily view bitmap index
    with open('bitmap.csv', 'w') as myfile:
        wr = csv.writer(myfile, delimiter=":")
        wr.writerows(bitmap_index)

    # Writing to file
    data_structures = [names, headings, list(bitmap_index)]
    pickle.dump(data_structures, open("results.p", "wb"))
