# import os
# dirname = os.path.dirname(__file__)
# filename = os.path.join(dirname, 'relative/path/to/file/you/want')


def print_Content():
    f = open('C:\dvengine\ISCLK_LockTimeTest\221219-111651-286\ISCLK_LockTimeTest_00_bkLjpllLocktime___no_value___an04wclk0010_221219-111651-286.csv','r')
    contents = f.read
    print(contents)
    f.close()




def main():
    print_Content()



if __name__ == "__main__":main()


