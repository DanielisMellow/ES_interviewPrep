def GCDRecursive(a, b):
    if b == 0:
        return a
    else:
        return GCDRecursive(b, a % b)


def main():
    print(GCDRecursive(32, 12))


if __name__ == "__main__":
    main()
