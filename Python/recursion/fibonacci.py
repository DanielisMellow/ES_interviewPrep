

def fibonacci(n):
    if n < 2:
        return n
    return fibonacci(n-1) + fibonacci(n-2)



def listSum(aList):
    result = 0

    for val in aList:
        result += val
    return result

def listSumR(aList):
    if len(aList) == 0:
        return 0
    return aList[0] + listSumR(aList[1:])


def main():

    fibSeq = []
    for n in range(1,9):
    
        print(f"{n} : {fibonacci(n)}")
        fibSeq.append(fibonacci(n))
    
    #print(fibSeq)

    print(listSum(fibSeq))
    print(listSumR(fibSeq))

if __name__ == "__main__":main()