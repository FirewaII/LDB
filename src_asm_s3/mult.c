#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t mult(uint64_t, uint64_t);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s a b (ou a et b sont >= 0)\n", argv[0]);
        return 1;
    }
    uint64_t a = atoi(argv[1]);
    uint64_t b = atoi(argv[2]);
    printf("%" PRIu64 " x %" PRIu64 " = %" PRIu64 "\n", a, b, mult(a, b));
    return 0;
}

