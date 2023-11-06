class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        """Check if the list is empty"""
        # return len(self.items) == 0
        """Pythonic way an empty list evaluates as false"""
        return not self.items

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        # Access the Last item on a list by using negative indices
        return self.items[-1]

    def size(self):
        return len(self.items)

    def __str__(self):
        return str(self.items)


if __name__ == "__main__":
    s = Stack()
    for nums in range(0, 10, 1):
        s.push(nums)
    print(s)

    for nums in range(0, 5):
        s.pop()
        print(s)

    print(s.size())
