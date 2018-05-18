#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t fact(uint64_t);

void erreur_fact(uint64_t n)
{
    printf("Fact(%" PRIu64 ") ne tient pas sur 64 bits !\n", n);
    // la fonction exit arrete proprement le programme
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s n\n", argv[0]);
        return 1;
    }
    uint64_t n = atoi(argv[1]);
    printf("Fact(%" PRIu64 ") = %" PRIu64 "\n", n, fact(n));
    return 0;
}

