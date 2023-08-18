
def main():
    seq = range(11)
    seq2 = [x *2 for x in seq]
    seq3 = [x for x in seq if x % 3  != 0 ]
    seq4 = [(x, x**2 )for x in seq]
    seq4 = [(x, x**2 )for x in seq if x % 3 == 0]


    from math import pi
    seq5 = [round(pi,x) for x in seq]

    print_list(seq)
    print_list(seq2)
    print_list(seq3)
    print_list(seq4)
    print_list(seq5)


def print_list(o):
    for i in o:
        print(i, end = ',')
    print()








if __name__ == '__main__': main()