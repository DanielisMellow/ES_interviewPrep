from string import ascii_lowercase

# Instead of a list we are going to use a deque (Double ended queue) like a list but optimized
# Optimized for insertion and deletion at either end

from collections import deque


class Queue:
    def __init__(self):
        self.items = deque()

    def is_empty(self):
        # return len(self.items) == 0
        return not self.items

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.popleft()

    def size(self):
        return len(self.items)

    def peek(self):
        return self.items[0]

    def __str__(self) -> str:
        return str(self.items)


if __name__ == "__main__":
    q = Queue()
    # print(q)
    # print(q.is_empty())
    # for letters in ascii_lowercase:
    #     q.enqueue(letters)

    # print(q)
    # while not q.is_empty():
    #     print(q.dequeue())

    q.enqueue ("Learning")
    q.enqueue ("with") 
    q.dequeue ()
    q.enqueue ("Linked")
    q.enqueue ("In")
    q.dequeue ()
    print (q)