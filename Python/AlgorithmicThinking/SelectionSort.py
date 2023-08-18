def swapPositions(list, pos1, pos2):
    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list


def SmallestElementIdex(data, idx=0):
    # Using the Enumerate function in Python
    min_idx = idx
    for i in range(idx + 1, len(data)):
        if data[i] < data[idx]:
            min_idx = i
    return min_idx


def selection_sort(xs):
    # The last value will automatically be in correct position.
    for i in range(len(xs) - 1):
        # Find minimum value in unsorted region.
        min_index = i
        for j in range(i + 1, len(xs)):
            # Update min_index if the value at j is lower than current minimum value.
            if xs[j] < xs[min_index]:
                min_index = j
        # After finding the minimum value in the unsorted region, swap with the first unsorted value.
        xs[i], xs[min_index] = xs[min_index], xs[i]


def main():
    data = [3, 2, 1, 5, 4]
    # print(SmallestElementIdex(data, 0))

    for i in range(len(data)):
        min_idex = SmallestElementIdex(data, i)
        data = swapPositions(data, i, min_idex)

    print(data)

    # A nice Pythonic way to check list is sorted.
    print(all(data[i] <= data[i + 1] for i in range(len(data) - 1)))


if __name__ == "__main__":
    main()
