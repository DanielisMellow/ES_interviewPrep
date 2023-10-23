#include <stdio.h>
// Iterate from 1 to 100
// Each time you are going to say a multiple of 3 replace it with "fizz"
// Each time you are going to say a multiple of 5 replace it with "buzz"
// Each time you are going to say a multiple of 3 and 5 replace it with "fizzbuzz"

void fizzBuzz()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 15 == 0)
            printf("fizzbuzz");
        else if (i % 5 == 0)
            printf("buzz");
        else if (i % 3 == 0)
            printf("fizz");
        else
            printf("%d", i);

        printf("\n");
    }
}

int main()
{

    fizzBuzz();
}
