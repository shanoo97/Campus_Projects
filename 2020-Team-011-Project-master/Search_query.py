import pickle
from PyQt5.QtWidgets import *
from PyQt5 import uic
import sys

# Load data structures from pickle file
data_structures = pickle.load(open("results.p", "rb"))

names = data_structures[0]
headings = data_structures[1]
bitmap = data_structures[2]


# Function to remove punctuation
def strip(s):
    punctuation = "!@#$%^'&*()_+<>?:.,;"
    for c in s:
        if c in punctuation:
            s = s.replace(c, "")
    return s.lower()


# Hash function used for hashing
def hash_djb2(s):
    hash = 5381
    for x in s:
        hash = ((hash << 5) + hash) + ord(x)
    return hash % 100


# Search function for hash tables
def search(hash_table, key):
    value = key
    key = hash_djb2(key)
    if key in hash_table:
        for element in hash_table[key]:
            if element == value:
                return True
    return False


# Function that calculates and returns debates given speakers
def getdebates(name1, name2):
    debates = []

    if name1 == '' or name2 == '':
        name = name1 + name2
        if search(names, name):
            for i, element in enumerate(bitmap[0]):
                if element == name:
                    index1 = i
            for element in bitmap:
                if element[index1] == 1:
                    debates.append(element[0])


    elif search(names, name1) and search(names, name2):
        for i, element in enumerate(bitmap[0]):
            if element == name1:
                index1 = i
            if element == name2:
                index2 = i
        output = []
        for element in bitmap:
            if element[index1] == 1 and element[index2] == 1:
                output.append(1)
            else:
                output.append(0)
        for index, values in enumerate(output):
            if values == 1:
                debates.append(bitmap[index][0])
    return debates


# Function that calculates and returns speakers given debates
def getspeakers(speaker1, speaker2):
    speakers = []

    if speaker1 == '' or speaker2 == '':
        speaker = speaker1 + speaker2
        if search(headings, speaker):
            for i, element in enumerate(bitmap):
                if element[0] == speaker:
                    index1 = i
            for i, element in enumerate(bitmap[index1]):
                if element == 1:
                    speakers.append(bitmap[0][i])

    elif search(headings, speaker1) and search(headings, speaker2):
        for i, element in enumerate(bitmap):
            if element[0] == speaker1:
                index1 = i
            if element[0] == speaker2:
                index2 = i
        output = []
        for i in range(len(bitmap[0])):
            if bitmap[index1][i] == 1 and bitmap[index2][i] == 1:
                output.append(1)
            else:
                output.append(0)
        for index, values in enumerate(output):
            if values == 1:
                speakers.append(bitmap[0][index])
    return speakers


# Class for GUI
class UI(QMainWindow):
    def __init__(self):
        super(UI, self).__init__()
        uic.loadUi("window.ui", self)
        self.show()
        self.debates.pressed.connect(self.printdebates)
        self.speakers.pressed.connect(self.printspeakers)

    # Print debates to GUI
    def printdebates(self):
        self.tb.clear()
        debates = getdebates(strip(self.name1.text()), strip(self.name2.text()))
        for debate in debates:
            self.tb.insertPlainText(debate.upper() + "\n")

    # Print speakers to GUI
    def printspeakers(self):
        self.tb.clear()
        speakers = getspeakers(strip(self.debate1.text()), strip(self.debate2.text()))
        for speaker in speakers:
            self.tb.insertPlainText(speaker.upper() + "\n")


# Launch GUI
app = QApplication(sys.argv)
w = UI()
sys.exit(app.exec_())
