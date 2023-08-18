import random

PUZZLE_SIZE = 5


def createPuzzleNums(size):
    # Create random puzzle
    # random.sample ensures no duplicates
    return random.sample(range(100), size)


def createPuzzleConstraints(size):
    # Randomly assign inequalities
    puzzle = []
    for i in range(size - 1):
        puzzle.append(">" if random.random() < .5 else "<")

    return puzzle

def solvePuzzle(puzzle_nums, puzzle_symbols):
    # Sort puzzle numbers first
    # Use largest remaining if greater than, smallest remaining if less than
    sorted_puzzle_nums = sorted(puzzle_nums, reverse=True)

    # Vars for the "two pointer" method
    high = 0
    low = PUZZLE_SIZE - 1

    # store solution values
    solution_values = []

    # Integrate through the puzzle symbols and apply solution algorithm
    for symbol in puzzle_symbols:
        if symbol == ">":
            solution_values.append(sorted_puzzle_nums[high])
            high += 1
        elif symbol == "<":
            solution_values.append(sorted_puzzle_nums[low])
            low -= 1
    solution_values.append(sorted_puzzle_nums[high])

    # Convert solution_values to list of strings
    solution_values = list(map(str, solution_values))
    print(solution_values)
    # Create a list to store the final solution representation
    final_solution_representation = [None] * (len(solution_values) + len(puzzle_symbols))
    
    # Create solution representation using nifty slicing with step parameter
    final_solution_representation[::2] = solution_values
    final_solution_representation[1::2] = puzzle_symbols
    print(final_solution_representation)
    
    # Display final solution
    # The join() method takes all items in an iterable and joins them into one string
    print(" ".join(final_solution_representation))

    # Evaluate whether solution is correct. Some say eval is evil!
    print(eval(" ".join(final_solution_representation)))







def main():
    puzzleNums = createPuzzleNums(PUZZLE_SIZE)
    print(puzzleNums)
    puzzleSymbols = createPuzzleConstraints(PUZZLE_SIZE)

    solvePuzzle(puzzleNums,puzzleSymbols)


if __name__ == "__main__":main()