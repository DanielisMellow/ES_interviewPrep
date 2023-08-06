#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n)
{

    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;

    // int max_divisor = (int)(sqrt(n));
    // // printf("Max Divisor: %d\n", max_divisor);

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i * i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        printf("%d ", n);
}

int isPrimeOP(int n);
int main()
{

    for (int i = 1; i <= 10000; i++)
    {
        // printf("%d\n", i);
        if (isPrime(i))
        {
            printf("%d", i);
            printf("\n");
        }
        else
        {

            primeFactors(i);
            printf("\n");
        }
    }

    // for (int i = 1; i <= 100; i++)
    // {

    //     primeFactors(i);
    //     printf("\n");
    // }

    return 0;
}

// is prime or not
// Every prime number can be written in the form of 6n + 1 or 6n – 1
// (except the multiples of prime numbers, i.e. 2, 3, 5, 7, 11)
// , where n is a natural number.
int isPrimeOP(int n)
{
    // Check if n=1 or n=0
    if (n <= 1)
        return 0;
    // Check if n=2 or n=3
    else if (n == 2 || n == 3)
        return 1;
    // Check whether n is divisible by 2 or 3
    else if (n % 2 == 0 || n % 3 == 0)
        return 0;
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}