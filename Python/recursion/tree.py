class Node:
    def __init__(self, data, left=None, right=None) -> None:
        self.data = data
        self.left = left
        self.right = right


def preorder_print(root, path=""):
    """Root->Left->Right"""
    if root:
        path += str(root.data) + "-"
        path = preorder_print(root.left, path)
        path = preorder_print(root.right, path)
    return path


def inorder_print(root, path=""):
    """Left->Root->Right"""
    if root:
        path = inorder_print(root.left, path)
        path += str(root.data) + "-"
        path = inorder_print(root.right, path)
    return path


def postorder_print(root, path=""):
    """Left->Right->Root"""
    if root:
        path = postorder_print(root.left, path)
        path = postorder_print(root.right, path)
        path += str(root.data) + "-"
    return path


def main():
    r"""
            ______F______
            /             \
        __D__           __I__
        /     \         /     \
        B       E       G       J
       / \               \
      A   C               H
    """

    # Set up tree:
    root = Node("F")
    root.left = Node("D")
    root.left.left = Node("B")
    root.left.left.left = Node("A")
    root.left.left.right = Node("C")
    root.left.right = Node("E")
    root.right = Node("I")
    root.right.left = Node("G")
    root.right.left.right = Node("H")
    root.right.right = Node("J")

    print("Preorder:\t", preorder_print(root))
    print("Inorder:\t", inorder_print(root))
    print("Postorder\t", postorder_print(root))


if __name__ == "__main__":
    main()
