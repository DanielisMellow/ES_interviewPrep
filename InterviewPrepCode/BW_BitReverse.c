#include <stdio.h>
#include <stdint.h>

void printBinary(uint8_t n)
{
    int size = sizeof(uint8_t) * 8 - 1;

    for (int i = size; i > -1; i--)
    {
        (1 & n >> i) ? printf("1") : printf("0");
    }
    printf("\n");
}

uint8_t reverse(uint8_t b)
{
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

uint8_t reverseBitsV2(uint8_t n)
{
    uint8_t numOfBits = sizeof(n) * 8;
    uint8_t reversedNum = 0;

    for (int i = 0; i < numOfBits; i++)
    {
        // Checking if the i-th bit is set
        if (1 & (n >> i))
            // Set the (numOfBits - 1 -i)-th bit in the reversedNum
            reversedNum |= 1 << (numOfBits - 1 - i);
    }

    return reversedNum;
}

int main()
{

    uint8_t c = 128;
    printBinary(c);
    c = reverseBitsV2(c);
    printBinary(c);

    return 0;
}

// OUTPUT
// 10000000
// 00000001
