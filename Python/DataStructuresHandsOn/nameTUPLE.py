from collections import namedtuple


def can_take_order(driver, numper_packages):
    return driver.car_capacity >= numper_packages


def main():
    Driver = namedtuple("driver", ["name", "car_type", "car_capacity"])

    irs = Driver("Iris", "Prius", 7)
    mickie = Driver("Mickie", "Tucson", 15)
    witty = Driver("Witty", "Hummer", 26)

    print(can_take_order(witty, 20))


if __name__ == "__main__":
    main()
