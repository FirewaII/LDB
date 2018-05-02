#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define X 5

#define PLUS(a, b) (a + b)

int main(void)
{
    uint32_t x2 = X * X;
    printf("x = %" PRIu32 "\n", x2);

    printf("9 * 10 = %" PRIu32 "\n", PLUS(5, 4) * 10);

    for (int8_t i = 10; i >= 0; i--) {
        printf("i = %" PRIu8 "\n", i);
    }

    uint8_t i = 0;
    while (i < 10){
        printf("i = ");
        printf("%" PRIu8 "\n", i);
        i++;
    }

    char *chaine1 = "abc";
    // n'oublions pas l'octet pour stocker le '\0' final
    char *chaine2 = malloc(strlen(chaine1) + 1 + 1);
    // on concatene le caractere 'd' a la fin de la chaine
    char *d = "d";
    strcpy(chaine2, chaine1);
    strcat(chaine2, d);
    printf("%s + 'd' = %s\n", chaine1, chaine2);
    free(chaine2);

    return 0;
}
