from prettytable import PrettyTable


def Convert(lst):
    dct = {lst[i]: lst[i + 1] for i in range(0, len(lst), 2)}
    return dct


def prettyTable():
    x = PrettyTable()
    x.field_names = ["regfield", "status"]
    x.add_row(["One", 1])
    x.add_row(["Two", 2])
    x.add_row(["Three", 3])

    print(x)


def main():
    prettyTable()

    dict = {
        "one": 1,
        "Two": 2,
        "Three": 3,
    }

    print(dict)


if __name__ == "__main__":
    main()
