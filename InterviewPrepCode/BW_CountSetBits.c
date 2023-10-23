#include <stdio.h>

// Return A binary String conversion of a number
// Short is 2 bytes a byte is 8 bits
char *binString(short n)
{
    static char bin[17];

    for (int i = 0; i < 16; i++)
    {
        bin[i] = (n & 0x8000) ? '1' : '0';

        n <<= 1;
    }
    bin[16] = '\0';

    return bin;
}

// Print a Binary Representation of a number
void printBinary(short n)
{
    short size = sizeof(n) * 8 - 1;

    for (int i = size; i >= 0; i--)
    {
        (1 & n >> i) ? printf("1") : printf("0");
    }
    printf("\n");
}

// Count set bits Typical Approach
int countSetBits(short n)
{
    int size = sizeof(n) * 8;
    int count = 0;

    for (int i = 0; i < size; i++)
        if (1 & n >> i)
            count++;

    return count;
}

// Count Set Bits Optimized
int countSetBitsOP(short n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main()
{
    short x = 7;

    // printf("%d", sizeof(x));

    printf("Number: %d\n", x);
    printf("Binary Representation: %s\n", binString(x));
    printBinary(x);
    // printf("Hamming Weight: %d\n", countSetBits(x));
    // printf("Hamming Weight Optimized: %d", countSetBitsOP(x));
}