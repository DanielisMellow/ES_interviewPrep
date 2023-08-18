
import sys
from traceRecursion import trace
sys.path.append("..")  # Adds higher directory to python modules path.

from functools import wraps




def factorialIterative(n):
    product = 1
    while(n >= 1):
        product *= n
        n -= 1
    
    return product

def factorialRecursive(n):
    
    if n <= 1:
        return 1    
    else:
        return n * factorialRecursive(n-1)     
   





# print(factorialIterative(4))
# assert factorialIterative(4) == 24
# print(factorialRecursive(3))


factorial = trace(factorialRecursive)
factorial(5)

