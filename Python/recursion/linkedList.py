class Node:
    def __init__(self, data, nxt=None) -> None:
        self._data = data
        self._nxt = nxt  # Next is a keyword in python

    def get_nxt(self):
        return self._nxt

    def set_nxt(self, nxt):
        self._nxt = nxt

    def get_data(self):
        return self._data

    def set_data(self, data):
        self._data = data

    # @property
    # def node_data(self):
    #     return self._data

    # @node_data.setter
    # def node_data(self, val):
    #     print(f"{self._data} is now {val}")
    #     self._data = val

    # @node_data.deleter
    # def node_data(self):
    #     del self._data

    # @property
    # def node_next(self):
    #     return self._nxt

    # @node_next.setter
    # def node_next(self, nxt):
    #     self._nxt = nxt

    # @node_next.deleter
    # def node_next(self):
    #     del self._nxt


def traverse(head: Node):
    while head._nxt is not None:
        print(head._data)
        head = head._nxt
    else:
        print(head._data)


def traverseR(head):
    if head is None:
        return
    print(head._data)
    traverse(head._nxt)


def main():
    # item3 = Node("Horse")
    # item3.node_data = "Godzilla"
    # item2 = Node("cat")
    # item1 = Node("dog")

    # item1.node_next = item2
    # item2.node_next = item3
    # item3.node_next = None

    # item3 = Node("Horse")
    # item2 = Node("cat", item3)
    # item1 = Node("dog", item2)

    item3 = Node("Horse")
    item2 = Node("cat")
    item1 = Node("dog")

    item1.set_nxt(item2)
    item2.set_nxt(item3)

    print("")
    traverseR(item1)


if __name__ == "__main__":
    main()
