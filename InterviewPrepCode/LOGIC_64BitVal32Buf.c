#include <stdio.h>
#include <string.h>
#include <stdint.h>

void read32(uint64_t *reg, uint32_t *MSW, uint32_t *LSW)
{
    *MSW |= *reg >> 32;
    *LSW |= *reg;
}

void read32Buf(uint64_t *reg, uint32_t *buffer)
{
    static int toggle;

    toggle ^= 1;
    if (toggle)
    {
        *buffer |= *reg;
    }
    *buffer |= *reg >> 32;
}

int main(void)
{

    // register
    uint64_t reg = 0xAAAAAAAAFFFFFFFF;
    printf("64 bit register value: 0x%llx\n", reg);

    // buffers
    uint32_t high_buf_32 = 0;
    uint32_t low_buf_32 = 0;
    uint64_t buf_64 = 0;

    read32Buf(&reg, &low_buf_32);
    printf("LSW: 0x%x\n", low_buf_32);
    read32Buf(&reg, &high_buf_32);
    printf("MSW: 0x%x\n", high_buf_32);

    // read32(&reg, &high_buf_32, &low_buf_32);
    // printf("LSW: 0x%x\n", low_buf_32);
    // printf("MSW: 0x%x\n", high_buf_32);

    buf_64 |= (uint64_t)high_buf_32 << 32;
    buf_64 |= (uint64_t)low_buf_32;

    printf("64 bit register value: 0x%llx\n", buf_64);
    return 0;
}