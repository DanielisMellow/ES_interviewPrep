# Library that allows Python script to interact with the command line interface or shell
import subprocess

for i in range(0, 5):
    subprocess.check_call(["python3", "example.py"])
