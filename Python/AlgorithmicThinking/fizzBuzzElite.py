def fizzbuzz(n):
    mappings = {3: "Fizz", 5: "Buzz", 7: "Pazz"}

    result = ""

    for key in mappings:
        if n % key == 0:
            result += mappings[key]
    if not result:
        result = str(n)

    return result


def main():
    for i in range(1, 101):
        print(fizzbuzz(i))


if __name__ == "__main__":
    main()
