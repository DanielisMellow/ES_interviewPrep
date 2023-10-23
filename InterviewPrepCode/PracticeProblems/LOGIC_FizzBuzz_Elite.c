#include <stdio.h>

typedef struct
{
    int key;
    const char *value;
} KeyValuePair;

KeyValuePair mappings[] =
    {
        {15, "FizzBuzz"},
        {5, "Buzz"},
        {3, "Fizz"},
};

void fizzBuzz(int n, KeyValuePair mappings[], int mappingSize)
{
    const char *result = NULL;

    for (int j = 0; j < mappingSize; j++)
    {
        if (n % mappings[j].key == 0)
        {
            result = mappings[j].value;
            break;
        }
    }

    if (result != NULL)
    {
        printf("%s", result);
    }
    else
    {
        printf("%d", n);
    }
    printf("\n");
}

int main()
{
    int mappingSize = sizeof(mappings) / sizeof(mappings[0]);
    for (int i = 1; i < 101; i++)
    {
        fizzBuzz(i, mappings, mappingSize);
    }
}