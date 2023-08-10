#include <stdio.h>
#include <stdint.h>

void setRegValue(int *REGISTER, uint64_t address, int value)
{

    REGISTER = (int *)address;
    *REGISTER = value;
}

int main()
{
    int x = 0;

    printf("Value at 0x%llx: %d\n", (uint64_t)&x, x);

    int *p = &x;
    uint64_t address = (uint64_t)&x;
    int value = 0xFF;

    setRegValue(p, address, value);
    printf("Value at 0x%llx: %d\n", (uint64_t)&x, x);
}
