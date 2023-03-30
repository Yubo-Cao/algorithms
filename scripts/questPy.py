import os
import subprocess
import sys

# Define the base path where the folder should be created
base_path = f"C:/Users/{os.getlogin()}/algorithms/gsmst/2023/"

# Get the name of the folder from the first command line argument
folder_name = sys.argv[1]

# Create the folder if it doesn't exist already
folder_path = os.path.join(base_path, folder_name)
if not os.path.exists(folder_path):
    os.makedirs(folder_path)

# Create the input and output files inside the folder
for suffix in ['in', 'out']:
    file_path = os.path.join(folder_path, f"1.{suffix}")
    open(file_path, 'a').close()  # create an empty file

# Create the main.py file
main_file_path = os.path.join(folder_path, "main.py")
open(main_file_path, 'a').close()  # create an empty file

# Open all three files in a new instance of vscode
code_path = "C:/Users/Anish/AppData/Local/Programs/Microsoft VS Code/bin/code.cmd"
subprocess.run([code_path, file_path])
