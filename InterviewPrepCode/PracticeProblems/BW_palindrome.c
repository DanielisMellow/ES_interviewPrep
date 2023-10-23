#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int isKthBitSet(uint8_t n, int k)
{
    if (n & 1 << (k - 1))
        return 1;

    return 0;
}

bool isBitPalindrome(uint8_t n)
{
    int i = 1;
    int j = sizeof(n) * 8;
    while (i < j)
    {
        if (isKthBitSet(n, i) != isKthBitSet(n, j))
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

char *BinaryString(uint8_t n, char *binString)
{
    int size = sizeof(uint8_t) * 8;
    binString = (char *)malloc(size + 1);

    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    {

        binString[j] = (1 & n >> i) ? '1' : '0';
        j++;
    }

    binString[8] = '\0';

    return binString;
}

// function to reverse bits of a number
uint8_t reverseBits(uint8_t n)
{
    uint8_t rev = 0;

    // traversing bits of 'n' from the right
    while (n > 0)
    {

        // bitwise left shift 'rev' by 1
        rev <<= 1;

        // if current bit is '1'
        if ((n & 1) == 1)
            rev ^= 1;

        // bitwise right shift 'n' by 1
        n >>= 1;
    }

    // required number
    return rev;
}

bool isPalindrome(unsigned int n)
{
    // get the number by reversing bits in the
    // binary representation of 'n'
    unsigned int rev = reverseBits(n);

    return (n == rev);
}

int main()
{

    uint8_t n = 8;
    n = n - 1;

    char *p = NULL;

    p = BinaryString(n, p);

    printf("Is %s a valid bit palindrome: %s", p, isBitPalindrome(n) ? "True" : "False");

    free(p);
    return 0;
}