import time
import random


def waiting_game():
    target = random.randint(2, 4)
    print(f"\n Target time is {target} sec")

    input("---Pres Enter to Begin---")
    start = time.perf_counter()

    input(f"\n...Pres Enter again after {target} sec...")
    elapsed = time.perf_counter() - start

    print(f"\n Elapsed time: {elapsed : .3f} seconds")

    if elapsed == target:
        print("Perfect!")
    elif elapsed < target:
        print(f"{target - elapsed : .3f} seconds too fast")
    elif elapsed > target:
        print(f"{elapsed - target : .3f} seconds too slow")


def main():
    waiting_game()


if __name__ == "__main__":
    main()
