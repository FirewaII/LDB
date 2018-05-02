#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <inttypes.h>

void echange(int32_t a, int32_t b)
{
    int32_t t;
    t = a;
    a = b;
    b = t;
}

int32_t *fct1(void)
{
    int32_t x = 5;
    int32_t *p = &x;
    return p;
}

void fct2(void)
{
    int32_t tab[] = {1, 2, 3, 4};
    (void)tab;
}

void fct3(void)
{
    int32_t *ptr = malloc(sizeof(int32_t));
    assert(ptr != NULL);
    printf("Valeur de l'entier alloue : %" PRId32 "\n", *ptr);
    free(ptr);
}

void fct4(void)
{
    int32_t *tab[10];
    for (int i = 0; i < 10; i++) {
        tab[i] = malloc(sizeof(int32_t));
        assert(tab[i] != NULL);
    }
}

void fct5(void)
{
    int32_t *ptr1 = malloc(sizeof(int32_t));
    int32_t *ptr2 = ptr1;
    free(ptr1);
    *ptr2 = 5;
    printf("Valeur de ptr2 : %" PRId32 "\n", *ptr2);
}

void fct6(void)
{
    const uint32_t taille = 10;
    int32_t *tab = malloc(taille);
    for (uint32_t i = 0; i < taille; i++) {
        tab[i] = 5 - i;
    }
}

void fct7(int32_t tab[])
{
    printf("Taille du tableau (en octets) : %" PRIu32 "\n", (uint32_t)sizeof(tab));
}

int main(void)
{
    int32_t a = 5;
    int32_t b = 7;
    printf("Valeurs initiales : a = %" PRId32 ", b = %" PRId32 "\n", a, b);
    echange(a, b);
    printf("Valeurs echangees : a = %" PRId32 ", b = %" PRId32 "\n", a, b);
    puts("");
    int32_t *x = fct1();
    printf("Valeur x = %" PRId32 "\n", *x);
    fct2();
    printf("Valeur x = %" PRId32 "\n", *x);
    puts("");
    fct3();
    puts("");
    fct4();
    fct5();
    puts("");
    fct6();
    int32_t tab[10];
    printf("Taille du tableau (en octets) : %" PRIu32 "\n", (uint32_t)sizeof(tab));
    fct7(tab);
    puts("");
    return 0;
}
