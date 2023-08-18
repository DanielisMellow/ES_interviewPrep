def is_primeV1(n):
    """Return True if n is a prime number. False otherwise"""
    if n == 1:
        return False  # 1 is not prime
    # Check all numbers till n - 1  range function is not inclusive
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


# improving by reducing the amount of divisors you need to test without repeating using sqr
def is_primeV2(n):
    """Return True if n is a prime number. False otherwise"""
    if n == 1:
        return False  # 1 is not prime
    # Check all numbers till n - 1  range function is not inclusive
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


# determines if a number is prime
# Improvement by only checking the odd numbers up to the (sqrt of n) + 1
def is_prime(n):
    """
    Returns True if n is prime, False otherwise.
    """
    if n <= 1:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False
    else:
        # check odd numbers up to the square root of n
        for i in range(3, int(n**0.5) + 1, 2):
            if n % i == 0:
                return False
        return True


def prime_factor(number: int):
    """
    Returns list of prime factorization
    """
    factors = []
    divisor = 2
    while divisor <= number:
        if number % divisor == 0:
            factors.append(divisor)
            number = number // divisor
        else:
            divisor += 1

    return factors


def main():
    n = 128

    numbers = prime_factor(n)
    print(numbers)

    result = map(is_prime, numbers)

    # convert the result to a list and print the prime numbers
    prime_numbers = list(filter(lambda x: x != False, result))
    print(prime_numbers)


if __name__ == "__main__":
    main()
