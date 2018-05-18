
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t fibo(uint64_t);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s n (ou n est >= 0)\n", argv[0]);
        return 1;
    }
    uint64_t n = atoi(argv[1]);
    printf("Fibo(%" PRIu64 ") = %" PRIu64 "\n", n, fibo(n));
    return 0;
}

