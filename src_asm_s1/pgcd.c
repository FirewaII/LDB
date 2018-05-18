#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// la fonction pgcd est definie dans un autre fichier
uint32_t pgcd(void);

// ces deux variables globales sont publiques
uint32_t a;
uint32_t b;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s a b (ou a et b sont > 0)\n", argv[0]);
        return 1;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if ((a == 0) || (b == 0)) {
        fprintf(stderr, "Erreur : les entiers doivent etre strictement positifs\n");
        return 2;
    }
    uint32_t x = a;
    uint32_t y = b;
    printf("PGCD(%" PRIu32 ", %" PRIu32 ") = %" PRIu32 "\n", x, y, pgcd());
    return 0;
}

