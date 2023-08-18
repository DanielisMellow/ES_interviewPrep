def index_all(search_list, item):
    index_list = []
    for index, value in enumerate(search_list):
        # print(f"{index}: {value}")
        if value == item:
            index_list.append([index])
        elif isinstance(search_list[index], list):
            for i in index_all(search_list[index], item):
                index_list.append([index] + i)
    return index_list


def main():
    nums = [[[1, 2, 3], 2, [1, 3]], [1, 2, 3]]

    print(index_all(nums, 2))


if __name__ == "__main__":
    main()
