#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t mult_simple(void);

uint64_t mult_egypt(void);

uint64_t mult_native(void);

uint64_t x, y;

double temps(double debut, double fin)
{
    return (double)(fin - debut) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s x y (ou x et y sont >= 0)\n", argv[0]);
        return 1;
    }

    x = atol(argv[1]); y = atol(argv[2]);
    printf("Res. attendu : %" PRIu64 "\n", x * y);
    printf("Mult. simple : %" PRIu64 "\n", mult_simple());
    x = atol(argv[1]); y = atol(argv[2]);
    printf("Mult. egypt. : %" PRIu64 "\n", mult_egypt());
    x = atol(argv[1]); y = atol(argv[2]);
    printf("Mult. native : %" PRIu64 "\n\n", mult_native());

    x = 111111111; y = 111111111;
    printf("Res. attendu : %" PRIu64 "\n", x * y);
    printf("Mult. simple : %" PRIu64 "\n", mult_simple());
    x = 111111111; y = 111111111;
    printf("Mult. egypt. : %" PRIu64 "\n", mult_egypt());
    x = 111111111; y = 111111111;
    printf("Mult. native : %" PRIu64 "\n\n", mult_native());

    x = 2; y = (1u << 31) - 1;
    printf("Res. attendu : %" PRIu64 "\n", x * y);
    clock_t debut = clock();
    uint64_t prod = mult_simple();
    clock_t fin = clock();
    printf("Mult. simple : %" PRIu64 " (temps d'execution : %f sec.)\n", prod, temps(debut, fin));

    const uint32_t cpt = 100 * 1000 * 1000;

    debut = clock();
    for (uint32_t i = 0; i < cpt; i++) {
        x = 2; y = (1u << 31) - 1;
        prod = mult_egypt();
    }
    fin = clock();
    printf("Mult. egypt. : %" PRIu64 " (temps d'execution : %f sec. pour %u iterations)\n", prod, temps(debut, fin), cpt);

    debut = clock();
    for (uint32_t i = 0; i < cpt; i++) {
        x = 2; y = (1u << 31) - 1;
        prod = mult_native();
    }
    fin = clock();
    printf("Mult. native : %" PRIu64 " (temps d'execution : %f sec. pour %u iterations)\n", prod, temps(debut, fin), cpt);

    return 0;
}

