def sort_words(input: str):
    words = input.split()
    words = [w.lower() + w for w in words]
    words.sort()
    words = [w[len(w) // 2 :] for w in words]
    return " ".join(words)


def sort_wordsV2(words: str) -> str:
    return " ".join(sorted(words.split(), key=str.casefold))


def iterate(nums: list):
    if len(nums) <= 1:
        return nums

    return [nums[0]] + iterate(nums[1:])


def main():
    words = "banana ORANGE apple"
    print(sort_wordsV2(words))

    nums = [1, 2, 3, 4]
    print(iterate(nums))


if __name__ == "__main__":
    main()
