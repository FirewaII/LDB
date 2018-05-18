#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

extern uint8_t val_binaire(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);

uint8_t chiffre(char c)
{
    if (c == '0') {
        return 0;
    } else if (c == '1') {
        return 1;
    } else {
        fprintf(stderr, "Erreur : %c n'est pas un chiffre en binaire\n", c);
        exit(2);
    }
}

int main(int argc, char *argv[])
{
    if ((argc != 2) || (strlen(argv[1]) != 8)) {
        fprintf(stderr, "usage: %s chaine_de_8_caracteres_representant_"
                "un_naturel_en_binaire_sur_8_bits\n  (par exemple : %s \"10100101\")\n",
                argv[0], argv[0]);
        return 1;
    }
    uint8_t val = val_binaire(chiffre(argv[1][0]), chiffre(argv[1][1]),
            chiffre(argv[1][2]), chiffre(argv[1][3]),
            chiffre(argv[1][4]), chiffre(argv[1][5]),
            chiffre(argv[1][6]), chiffre(argv[1][7]));
    printf("%s = %" PRIu8 "\n", argv[1], val);
    return 0;
}

