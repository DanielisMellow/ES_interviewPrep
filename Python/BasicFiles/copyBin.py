def main():
    infile = open('chikibeibi.jpg', 'rb')
    outfile = open('chikibeibi-copy.jpg', 'wb')
    while True: #infinite while loop until break
        buf = infile.read(10240) # Read a buffer full of size 10K bytes  small for most modern desktops
                                 # Copies file one chunk at a time 
        if buf: #Test if there is data in the buffer Empty buffer will have a false comparative value
            outfile.write(buf)
            print('.', end='', flush=True)
        else: break
    outfile.close() #close file to flush the buffer make sure the file is written properly 
    print('\ndone.')

if __name__ == '__main__': main()






