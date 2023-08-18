

def main():
    f = open('lines.txt')  # Open Function Returns a File Object default opens in read mode open('lines.txt','r') == open('lines.txt')
                           # Write mode 'w' empties the file and writes at the start of the file
                           #  Append mode 'a' adds contents to the end of the file 
    for line in f:              # The File Object is an iterator so you can use a For loop 
        print(line.rstrip())    # Each line is a string which has a method rstrip which strips line endings

if __name__ == '__main__':main()