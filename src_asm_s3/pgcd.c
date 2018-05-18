#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t pgcd(uint32_t, uint32_t);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s a b (ou a et b sont > 0)\n", argv[0]);
        return 1;
    }
    uint32_t a = atoi(argv[1]);
    uint32_t b = atoi(argv[2]);
    if ((a == 0) || (b == 0)) {
        fprintf(stderr, "Erreur : les entiers doivent etre strictement positifs\n");
        return 2;
    }
    printf("PGCD(%" PRIu32 ", %" PRIu32 ") = %" PRIu32 "\n", a, b, pgcd(a, b));
    return 0;
}

