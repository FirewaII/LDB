#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define TAILLE_MAX 6

uint64_t taille_chaine(void);

void inverse_chaine(void);

char chaine[TAILLE_MAX];

int main(void)
{
    char *chaines[] = {"", "a", "ab", "abc", "abcd", "abcde", NULL};
    for (uint32_t i = 0; chaines[i]; i++) {
        strcpy(chaine, chaines[i]);
        printf("Chaine : \"%s\"\n", chaine);
        uint64_t taille = taille_chaine();
        printf("Taille : %" PRIu64 "\n", taille);
        inverse_chaine();
        printf("Chaine inversee : \"%s\"\n", chaine);
        puts("");
    }
    return 0;
}

