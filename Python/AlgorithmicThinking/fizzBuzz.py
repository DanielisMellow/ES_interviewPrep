for i in range(1, 101):
    # check for fizzbuzzness first because it needs to be true for both
    if not i % 15:
        print("fizzbuzz")
    elif not i % 5:
        print("buzz")
    elif not i % 3:
        print("fizz")
    else:
        print(i)
