from functools import wraps
from time import perf_counter, sleep


def get_Time(func):
    """Times any Function"""

    def wrapper(*args, **kwargs):
        star_time = perf_counter()

        func(*args, **kwargs)

        end_time = perf_counter()

        total_time = round(end_time - star_time, 2)
        print("Time", total_time, "sec")

    return wrapper


@get_Time
def doSomething(param: str):
    """Does Something important"""
    sleep(1)
    print(param)


def main():
    doSomething("Hello!")


if __name__ == "__main__":
    main()
