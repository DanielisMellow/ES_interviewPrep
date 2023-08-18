

secret = 'Lizards'
pw = ''
count = 0
max_attempt = 5


while pw != secret:
   count +=1
   if count > max_attempt:
    print('Failed to Answer: You are not the chosen one')
    break;
   pw =  input(f'{count}: Daniel is the king of the? ')

else:
    print('Successfully Logged in :) ')