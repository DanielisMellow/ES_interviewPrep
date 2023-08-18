from collections import namedtuple
from csv import reader


def main():
    with open("data/customer.csv", "r") as open_csv:
        read = reader(open_csv)
        Person = namedtuple("Person", next(read))
        for line in read:
            person = Person(*line)
            print(person)

    return


if __name__ == "__main__":
    main()
