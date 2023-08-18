def main():
    ## Dictionary is an associative array 
    game = {'Rock':'One','Paper':'Two','Scissors':'Three'}

    for k, v in game.items():
        print(f'{k}:{v}')
    
    print()


    game1 = dict(Rock = 'One',Paper = 'Two', Scissors = 'Three')
    
    print_dic(game1)

def print_dic(dic):
    for i in dic:
        print(f'{i}: {dic[i]}')
        print()

if __name__ == '__main__':main()