def linear_search(data, target):
    for i in data:
        if target == data[i]:
            return i
    return -1



def linear_searchV1(data, target):
    # Using the Enumerate function in Python
    for i, val in enumerate(data):
        if val == target:
            return i    # Early Exit 
    return -1


data = [4, 5, 2, 7, 1, 8]
target = 8
result = linear_searchV1(data, target)
if result == -1:
    print("Item not found.")
else:
    print(f"Item found at position {result}.")