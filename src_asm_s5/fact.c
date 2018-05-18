#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t fact(uint32_t);

void erreur_fact(uint32_t n)
{
    printf("Fact(%" PRIu32 ") ne tient pas sur 32 bits !\n", n);
    // la fonction exit arrete proprement le programme
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s n\n", argv[0]);
        return 1;
    }
    uint32_t n = atoi(argv[1]);
    printf("Fact(%" PRIu32 ") = %" PRIu32 "\n", n, fact(n));
    return 0;
}

