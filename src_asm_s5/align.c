#include <stdio.h>
#include <inttypes.h>

extern void affiche_asm(char, uint16_t);

void affiche_c(char c, uint16_t s)
{
    printf("Caractere = %c, Short = %" PRIu16 "\n", c, s);
}

int main(void)
{
    char c = 'a';
    uint16_t s = 1024;
    affiche_asm(c, s);
    return 0;
}

