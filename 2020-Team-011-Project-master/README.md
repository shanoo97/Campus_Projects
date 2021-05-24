

Instructions:
The project indexing algorithm must be run using a Python virtual environment. This can be achieved by following the instructions below:

1. Ensure Python 3.6+ is installed and pip is installed for Python

2. The program must be run under a Python environment which can be done by following the commands in this link:
`https://linuxize.com/post/how-to-create-python-virtual-environments-on-ubuntu-18-04/`

3. Set up virtual environment:
`virtualenv venv`

4. Activate the virtual environment using:
`source venv/bin/activate`

5. Install modules from requirements.txt
`pip3 install -r requirements.txt`

Running Files:

The scripts can be run using the following command structure:
`python3 <filename.py>`

*Note the scripts load certain files, such as the XML hansard document and results.p file from the working directory. Change the path of the file if required. Addtionally the Number of threads is set to 2 and should be changed from script if required.

Testing the scripts:  
Command for code profiling :  
`python3 -m cProfile Indexing.py`  
Command to generate cpu usage plot:  
`psrecord "python3 Indexing.py" --plot plot.png --include-children`  
Additionally the `htop` or `top` command can be used to check cpu usage  

