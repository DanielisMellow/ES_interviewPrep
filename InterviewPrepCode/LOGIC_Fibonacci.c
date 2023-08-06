#include <stdio.h>

int fibonacci(int n)
{
    if (n < 2)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        int f = fibonacci(i);
        for (int j = 0; j < f; j++)
            printf("+");
        printf("%d\n", f);
    }
}