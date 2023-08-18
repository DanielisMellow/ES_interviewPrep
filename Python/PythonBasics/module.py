import sys
import os


def main():
    #system related function
    v = sys.version_info
    print('Python version {}.{}.{}'.format(*v))
    print(sys.platform)

    #OS related modules 
    print(os.name)
    x = os.getenv('PATH')
    print(x)

if __name__ == '__main__':main()
