import stack

string = "gnivorpmi peek syawlA ,leinaD nac uoy sa hcum sA nraeL"
reversed_string = ""
s = stack.Stack()

# Your solution here.
for char in string:
    s.push(char)

while not s.is_empty():
    reversed_string += s.pop()

# Pythonic Way
# reversed_string = string[::-1]

print(reversed_string) 
