class Book:
    def __init__(self, title, author, price):
        super().__init__()
        self.title = title
        self.author = author
        self.price = price

    # The __str__ function is used to return a user-friendly string
    # representation of the object
    def __str__(self):
        return f"{self.title} by {self.author}, costs {self.price}"

    # The __repr__ function is used to return an obj representation (Developer facing string) used for debugging purposes 
    # representation of the object
    def __repr__(self):
        return f"title={self.title},author={self.author},price={self.price}"


b1 = Book("War and Peace", "Leo Tolstoy", 39.95)

# print object
print(b1)

# use str() and repr()
print(str(b1))
print(repr(b1))
