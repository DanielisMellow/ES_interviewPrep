
class Book():
    BOOK_TYPES = ("HARDCOVER", "PAPERBACK", "EBOOK")
    __booklist = None    

    @classmethod
    def getBookTypes(cls):
        return cls.BOOK_TYPES

    @staticmethod
    def getBookList():
        if Book.__booklist == None:
            Book.__booklist = []
        return Book.__booklist

    def __init__(self,title,bookType):  #initializer function
        self.title = title
        if (not bookType in Book.BOOK_TYPES):
            raise ValueError(f"{bookType} is not a valid book type")
        else:
            self._BOOK_TYPE = bookType

 
 
 
def main():
 #Instance of a class
  b1 = Book('1984',"HARDCOVER")
  #Print the class and property
  print(b1.title)

  thebooks = Book.getBookList()
  thebooks.append(b1)

  print(thebooks)

if __name__ == '__main__':main()
