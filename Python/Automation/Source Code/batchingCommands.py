import sys
import random
import subprocess
def generateFiles(numFiles, nameFiles):
    for i in range(0,numFiles):
        postfix = str(i) + '.txt'
        postfixDir = str(i)
        subprocess.check_call(['mkdir','example' + postfixDir])
        temp = open(nameFiles + postfix, 'w')
        temp.write(str(random.randint(1,10)))
        temp.close()
        subprocess.check_call(['mv', nameFiles + postfix, 'example' + postfixDir])
    return

def main():
    numFiles = int(sys.argv[1])
    nameFiles = str(sys.argv[2])
    generateFiles(numFiles, nameFiles)

main()

