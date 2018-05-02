#include "liste_bugs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static void init_tab(uint32_t tab[], uint32_t taille)
{
    for (uint32_t i = 0; i < taille; i++) {
        tab[i] = random() % taille;
    }
}

static void affiche_tab(uint32_t tab[], uint32_t taille)
{
    printf("  T  : ");
    fflush(stdout);
    for (uint32_t i = 0; i < taille; i++) {
        printf("%" PRId32 " ", tab[i]);
    }
    puts("");
}

int main(void)
{
    srandom(time(NULL));
    const uint32_t taille = 10;
    uint32_t tab[taille];
    init_tab(tab, taille);
    puts("Tableau initial :");
    affiche_tab(tab, taille);
    struct liste_t *liste = init_liste(tab, taille);
    puts("Liste initiale :");
    affiche_liste(liste, false);
    affiche_liste(liste, true);
    trie_liste(liste);
    puts("Liste triee :");
    affiche_liste(liste, false);
    affiche_liste(liste, true);
    detruis_liste(&liste);
    return 0;
}

