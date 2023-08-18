def multiplication(a, b):
    """Multiplication of positive integers using Recursion"""
    nums = []
    nums.extend([a, b])
    nums.sort()
    b = nums[0]
    a = nums[1]

    if b == 1:
        return a
    return a + multiplication(a, b - 1)


def exponents(a, n):
    if n == 1:
        return a
    return a * exponents(a, n - 1)


def stringLength(s):
    if len(s) == 1:
        return 1
    return 1 + stringLength(s[1:])


def stringLengthIter(a):
    result = 0
    for i in range(len(a)):
        result += 1

    return result


def main():
    print(multiplication(4, 5))

    print(exponents(2, 10))
    print(2**10)
    s = "Hello_World!"

    print(len(s))
    print(stringLengthIter(s))
    print(stringLength(s))


if __name__ == "__main__":
    main()
