def main():
    game = ['Rock','Paper','Scissors']
    #List are zero based select specific item
    ##print(game[0])
    i = game.index('Paper')
    print(f'The index that contains Paper: {i}')

    print_list(game)

def print_list(args):
    for i in args:
        print(i, end = ' ', flush = True)
        print()

if __name__ == '__main__':main()