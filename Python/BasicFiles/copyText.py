
def main():
    infile = open('lines.txt', 'rt')    #input file opened in read text mode (default)
    outfile = open('lines-copy.txt', 'wt') #opening output file write text mode (default)
    for line in infile: 
        print(line.rstrip(), file=outfile)  #Strip line endings with rstrip and print/write to output file
        print('.', end='', flush=True)      #Print dot for each line of text #flush output buffer
    outfile.close()                         #Close file you have written too
    print('\ndone.')

if __name__ == '__main__': main()




