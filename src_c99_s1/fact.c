#include <stdio.h>
#include <inttypes.h>

uint32_t fact(uint32_t n)
{
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main(void)
{
    uint32_t x = 5;
    uint32_t f = fact(x);
    printf("Fact(%" PRIu32 ") = %" PRIu32 "\n", x, f);
    return 0;
}

