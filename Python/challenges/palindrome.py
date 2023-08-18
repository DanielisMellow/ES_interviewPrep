from collections import deque


def check_palindrome(word):
    d = deque(word)
    while len(d) > 1:
        if d.pop() != d.popleft():
            return False

    return True


def is_palindrome(expression: str):
    """Returns True if expression is a Palindrome False Otherwise"""
    cleaned_expression = "".join(char.lower() for char in expression if char.isalpha())
    return cleaned_expression == cleaned_expression[::-1]


def main():
    expression = "Go Hang a salami, I'm a lasagna Hog"
    print(is_palindrome(expression))


if __name__ == "__main__":
    main()
