# def quickSort(arr: list):
#     if len(arr) < 2:
#         return arr
#     pivot = arr[0]

#     less = [val for i, val in enumerate(arr[1:]) if val < pivot]
#     greater = [val for i, val in enumerate(arr[1:]) if val >= pivot]
#     return quickSort(less) + [pivot] + quickSort(greater)


def quickSort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]
        return quickSort(less) + [pivot] + quickSort(greater)


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


def main():
    arr = [5, 2, 6, 1]
    # pivot = arr[0]

    # less = [val for i, val in enumerate(arr[1:]) if val < pivot]
    # greater = [val for i, val in enumerate(arr[1:]) if val >= pivot]
    # print(arr)
    # print(pivot)
    # print(less)
    # print(greater)

    print(quickSort(arr))
    # print(quicksort_verbose(arr))


if __name__ == "__main__":
    main()
