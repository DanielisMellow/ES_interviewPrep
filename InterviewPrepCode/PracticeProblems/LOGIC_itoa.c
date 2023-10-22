#include <stdio.h>
#include <stdbool.h>

void swap(char *a, char *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// A utility function to reverse a string
void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

// Implementation of citoa()
char *citoa(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

// Driver program to test implementation of itoa()
int main()
{
    char str[100];
    printf("Number: %d\nBase: %d\tConverted String: %s\n",
           1567, 10, citoa(1567, str, 10));
    printf("Base: %d\t\tConverted String: %s\n", 2,
           citoa(1567, str, 2));
    printf("Base: %d\t\tConverted String: %s\n", 8,
           citoa(1567, str, 8));
    printf("Base: %d\tConverted String: %s\n", 16,
           citoa(1567, str, 16));
    return 0;
}