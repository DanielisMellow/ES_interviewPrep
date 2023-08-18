def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)


# List comprehension


def quicksort_verbose(arr):
    print(f"Calling quicksort on {arr}")
    if len(arr) <= 1:
        print(f"returning {arr}")
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    print(f"left: {left}; ", end="")
    middle = [x for x in arr if x == pivot]
    print(f"middle: {middle}; ", end="")
    right = [x for x in arr if x > pivot]
    print(f"right: {right}")
    to_return = quicksort_verbose(left) + middle + quicksort_verbose(right)
    print(f"returning: {to_return}")
    return to_return


def quickSort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]
        return quickSort(less) + [pivot] + quickSort(greater)


def main():
    data = [3, 1, 4, 2]
    # print(quicksort(data))
    print(quicksort_verbose(data))

    # What about data with duplicates?
    # data = [1, 6, 5, 5, 2, 6, 1]
    # print(quickSort(data))


if __name__ == "__main__":
    main()
