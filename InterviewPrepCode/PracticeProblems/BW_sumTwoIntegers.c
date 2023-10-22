#include <stdio.h>

int getSum(int a, int b)
{
    while (b)
    {
        int tmp = (a & b) << 1;
        a = a ^ b;
        b = tmp;
    }
    return a;
}

int main()
{
    printf("The Sum of 5 + 100 = %d", getSum(5, 100));

    return 0;
}