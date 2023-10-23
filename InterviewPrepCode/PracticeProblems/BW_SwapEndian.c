#include <stdio.h>
#include <stdint.h>

uint32_t SwapEndians(uint32_t value)
{
    int byte0 = 0;
    int byte1 = 0;
    int byte2 = 0;
    int byte3 = 0;

    int result = 0;

    byte0 |= (value & 0x000000FF) >> 0;
    byte1 |= (value & 0x0000FF00) >> 8;
    byte2 |= (value & 0x00FF0000) >> 16;
    byte3 |= (value & 0xFF000000) >> 24;

    byte0 = byte0 << 24;
    byte1 = byte1 << 16;
    byte2 = byte2 << 8;
    byte3 = byte3 << 0;

    result = (byte0 | byte1 | byte2 | byte3);

    return result;
}

void changeAbsoluteMemory(int *reg, int AbsAddress, int value)
{

    reg = (int *)AbsAddress;

    *reg = value;
}

int main()
{

    return 0;
}