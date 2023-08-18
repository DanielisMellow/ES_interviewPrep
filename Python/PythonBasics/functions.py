def main():
    x = inclusive_range(5)
    for i in x:
        print(i, end = ' ')
    print()

    kitten()
    kittens('meow','hello','woof')
    kittenss(Buffy  = 'meow', Godzilla = 'RAWWWRRRRR', Kitten = 'Daddy')

   



def kitten(x=1):
    for i in range(x):
        print("Meow")

# Variable List Arguments (Traditional to call them *args)
def kittens(*args):
    if len(args):
        for i in args:
            print(i)
    else:
        print('MEOW.')


## Keyword arguments (Tradition to call them **kargs)

def kittenss(**kwargs):
    if len(kwargs):
        for k in kwargs:
            print('Kitten {} says {}'.format(k,kwargs[k]))
    else:
        print('MEOW')

##Generator 
def inclusive_range(*args):
    numargs = len(args)
    start = 0
    step = 1

    ##initialize parameters
    if numargs < 1:
        raise TypeError(f'Expected at least 1 argument, got {numargs}')
    elif numargs == 1:
        stop = args[0]
    elif numargs == 2:
        (start,stop) = args
    elif numargs == 3:
        (start,stop, step) = args
    else:
        raise TypeError(f'Expect at most 3 args, go{numargs}')
    
    #generator
    i = start
    while i <= stop:
        yield i
        i += step


if __name__ == "__main__":
    main()
