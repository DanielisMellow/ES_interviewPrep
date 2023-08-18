def make_change(target_amount):
    change = ""
    coins = 0
    coin_count = 0

    coins = target_amount // 25
    change += f"   {coins} quarters"
    coin_count += coins
    target_amount %= 25

    coins = target_amount // 10
    change += f"   {coins} dimes"
    coin_count += coins
    target_amount %= 10

    coins = target_amount // 5
    change += f"   {coins} nickles"
    coin_count += coins
    target_amount %= 5

    coins = target_amount // 1
    change += f"   {coins} pennies"
    coin_count += coins

    return coin_count, change


def exactChange(target_amount):
    #   Order is important
    coinTypes = [25, 10, 5, 1]
    # Initial Count
    coin_count = 0
    values = []

    for coin in coinTypes:
        while target_amount >= coin:  # Use current coin until value is too large
            target_amount -= coin
            values.append(coin)
            coin_count += 1
    return coin_count, values


def main():
    print(make_change(99))  # 3: 20p + 2p + 2p
    print(exactChange(99))


if __name__ == "__main__":
    main()
