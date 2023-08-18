"""

"""
# Basic Class Example
class Book:
    """
    Whenever you call in a method on a Python Object
    The Object itself gets automatically passed in as the first argument
    """

    BOOK_TYPES = ("HARDCOVER", "PAPERBACK", "EBOOK")

    @classmethod
    def getBookTypes(cls):
        return cls.BOOK_TYPES

    def __init__(self, **kwargs):
        # _attribute indicates encapsulated variables (Attributes to the object itself)
        # attributes with two underscore at the start "__secret" can't be seen outside the class (Used for subclasses)
        self._title = kwargs["title"] if "title" in kwargs else "NA"
        self._author = kwargs["author"] if "author" in kwargs else "NA"
        self._pages = kwargs["pages"] if "pages" in kwargs else "NA"
        self._price = kwargs["price"] if "price" in kwargs else "NA"

        _BOOK_TYPE = kwargs["bookType"] if "bookType" in kwargs else "NA"

        if (not _BOOK_TYPE in Book.BOOK_TYPES):
            raise ValueError(f"{_BOOK_TYPE} is not a valid book type")
        else:
            self._BOOK_TYPE = _BOOK_TYPE


    # Getters
    def getTitle(self):
        return self._title

    def getAuthor(self):
        return self._author

    def getPages(self):
        return self._pages

    def getPrice(self):
        if hasattr(self, "_discount"):
            return self._price - (self._price * self._discount)
        else:
            return self._price

    # Adding attributes after initialization
    def setDiscount(self, amount):
        self._discount = amount


def main():
    # Instance of a class
    b1 = Book(
        title="Thus Spoke Zarathustra",
        author="Friedrich Nietzsche",
        pages=252,
        price=22.00,
        bookType = 'HARDCOVER'
    )

    print(f"Price of {b1.getTitle()} Before Discount:")
    print(b1.getPrice())

    b1.setDiscount(0.25)
    print(f"Price of {b1.getTitle()} After the Discount:")
    print(b1.getPrice())
    print(type(b1))
    print(isinstance(b1,Book))

    print('Book Types: {}'.format(Book.getBookTypes()))



if __name__ == "__main__":
    main()
