import sched
import time


def schedule_function(event_time, function, *args):
    s = sched.scheduler(time.time, time.sleep)
    s.enterabs(event_time, 1, function, argument=args)
    print(f"{function.__name__}() scheduled for {time.asctime(time.localtime())}")
    s.run()


def main():
    schedule_function(time.time() + 10, print, "DANIEL", "Is the best!")


if __name__ == "__main__":
    main()
