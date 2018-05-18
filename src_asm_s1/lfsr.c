#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

// variable globale stockant la valeur aleatoire courante
// cette variable est publique car elle sera accedee depuis l'assembleur
uint16_t etat;

// fonction a ecrire en assembleur
extern void init_aleat(void);
// fonction a ecrire en assembleur
extern uint16_t aleat(void);

int main(void)
{
    // la periode du generateur est 2^16 - 1
    const uint32_t nbr = 65536;
    // tableau memorisant les valeurs deja vues
    bool *trouve = calloc(nbr, sizeof(bool)); assert(NULL != trouve);
    // initialisation du generateur
    init_aleat();
    uint16_t init = etat;
    // boucle enumerant les valeurs aleatoires
    for (uint32_t i = 0; i < nbr - 1; i++) {
        aleat();
        if (trouve[etat]) {
            puts("Erreur : valeur trouvee plusieurs fois !");
            return 1;
        } else {
            trouve[etat] = true;
        }
    }
    if (etat != init) {
        puts("Erreur : on n'est pas revenu a la valeur initiale !");
        return 1;
    }
    // verification qu'on a enumere toutes les valeurs possibles
    bool tous = true;
    for (uint32_t i = 1; (i < nbr) && tous; i++) {
        tous &= trouve[i];
    }
    if (!tous) {
        puts("Erreur : il manque des valeurs !");
        return 1;
    }
    puts("OK !");
    return 0;
}

