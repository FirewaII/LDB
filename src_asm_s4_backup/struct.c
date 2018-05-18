#include <stdio.h>
#include <inttypes.h>

struct structure_t {
    int64_t entier;
    char *ptr;
};

void affiche(uint64_t entier, char *ptr)
{
    printf("entier = %" PRId64 ", ptr = 0x%" PRIX64 "\n", entier, (uint64_t)ptr);
}

void affichage(struct structure_t);

void modification(uint64_t, char*, struct structure_t*);

int main(void)
{
    struct structure_t s = {-1, (char*)0xBADC0FFEE0DDF00D};
    affichage(s);
    modification(5, (char*)0xDEADC0DED15EA5E, &s);
    affichage(s);
    return 0;
}

