#include <inttypes.h>

int main(void)
{
    uint32_t x = 5;
    uint32_t *p = &x;
    *p = 7;
    p = (uint32_t *)10;
    *p = 5;
    return 0;
}

