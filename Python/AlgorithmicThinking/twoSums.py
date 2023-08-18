

def twoSum(arr,target):
    prevMap = {} # Val : Index

    for i, n in enumerate(arr):
        diff = target - n
        if diff in prevMap:
            return [prevMap[diff], i]
        prevMap[n] = i
    
    return []

# 2-Sum Interview Problem

def two_sum_problem(arr, target):

    sum_ind = []
    for i in range(len(arr) - 1 ):
        for j in range(i+1,len(arr)): 
              sum = arr[i] + arr[j]
              if sum == target:
                   sum_ind.append((i,j))

    
    return sum_ind



def twoSums(nums, target):
    # create an empty dictionary to store the indices
    seen = {}
    # loop over the array
    for i, num in enumerate(nums):
        # if the target minus the current number is in the dictionary, then return the indices
        if target - num in seen:
            return [seen[target - num], i]
        # otherwise, add the current index to the dictionary
        seen[num] = i
    # if no indices are found, return an empty list
    return []


# 2-Sum Interview Problem Solution

def two_sum_hash_table(arr, total):
    hash_table = {}
    for idx, val in enumerate(arr):
        complement = total - val
        if complement in hash_table:
            return idx, hash_table[complement]
        else:
            # The hash table stores the values from the array as keys, and the indices of
            # these values as the values in the table.
            print(f"Adding to hash table: key:{val}, value: {idx}")
        hash_table[val] = idx
    return None



def main():

   print(two_sum_problem([2, 1, 5, 3], 4))
   print(twoSum([2, 1, 5, 3], 4))

   print(two_sum_hash_table([2, 1, 5, 3], 4))

    # print(two_sum_problem([1, 2, 3], 4))
    # print(two_sum_problem([1234, 5678, 9012], 14690))
    # print(two_sum_problem([2, 2, 3], 4))
    # print(two_sum_problem([2, 2], 4))
    # print(two_sum_problem([8, 7, 2, 5, 3, 1], 10))

    



if __name__ == '__main__':main()