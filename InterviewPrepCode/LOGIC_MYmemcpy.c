#include <stdio.h>
#include <string.h>

void myMemCpy(void *dest, void *source, size_t n)
{
    char *d = (char *)dest;
    char *s = (char *)source;

    for (int i = 0; i < n; i++)
    {
        if (d + i == source || s + i == dest)
            break;

        d[i] = s[i];
    }
}

// Driver program
int main()
{

    int isrc[] = {10, 20, 30, 40, 50};
    int n = sizeof(isrc) / sizeof(isrc[0]);
    int idest[n];

    myMemCpy(idest, isrc, sizeof(isrc));
    printf("\nCopied array is ");

    for (int i = 0; i < n; i++)
        printf("%d ", idest[i]);

    return 0;
}
