#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint16_t age(uint16_t);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s annee_naissance\n", argv[0]);
        return 1;
    }
    uint16_t annee = atoi(argv[1]);
    printf("Vous avez donc %" PRIu16 " ans !\n", age(annee));
    return 0;
}

