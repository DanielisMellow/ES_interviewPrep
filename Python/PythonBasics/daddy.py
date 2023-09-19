def main():
    secret = "Daddy"
    user = ""
    count = 0

    while user != secret:
        if count > 0:
            print(f"I don't want to call you {user}...")
        user = input("What do you want to be called?: ")
        count += 1
    else:
        print("Okay I will call you {}".format(user))


if __name__ == "__main__":
    main()
