


# def fibonacci(n): 
# 	if n<0: 
# 		print("Incorrect input") 
# 	elif n==1: 
# 		return 0
# 	elif n==2: 
# 		return 1
# 	else: 
# 		return fibonacci(n-1)+fibonacci(n-2) 



def fibonacci(n):
	if n < 2:
		return n
	
	return fibonacci(n-1) + fibonacci(n-2)




def main():
	for i in range(8):
		print(fibonacci(i))




if __name__ == "__main__":main()