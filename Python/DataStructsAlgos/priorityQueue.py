import heapq


class PriorityQueue:
    def __init__(self):
        self.elements = []

    def is_empty(self):
        return not self.elements

    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def get(self):
        return heapq.heappop(self.elements)[1]

    def __str__(self):
        return str(self.elements)


if __name__ == "__main__":
    pq = PriorityQueue()
    print(pq)
    print(pq.is_empty())

    # item, priority
    # pq.put("eat", 2)
    # pq.put("code", 1)
    # pq.put("sleep", 3)
    pq.put("eat", 3)
    pq.put("code", 2)
    pq.put("smash", 1)

    print(pq)
    print(pq.get())
    print(pq.get())
    print(pq.get())
