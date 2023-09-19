# Represent the doors as a list of booleans False = close True = open
# Offset list by 1 ignore 0 index
doors = [False] * 101

# Iterate through through the doors with nested for loops
for i in range(1, 101):
    for j in range(i, 101, i):
        doors[j] = not doors[j]

# Print the Outcome
print("Doors: ", end="")
for i in range(1, 101):
    if doors[i]:
        print(i, end=", ")
