#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

void tri_nain(int32_t[], uint64_t);

void tri_nain_opt(int32_t[], uint64_t);

void afficher_tab(int32_t tab[], uint64_t taille)
{
    for (uint64_t i = 0; i < taille; i++) {
        printf("%" PRId32 " ", tab[i]);
    }
    printf("\n");
}

int32_t comp(const void *a, const void *b)
{
    return *(int32_t*)a - *(int32_t*)b;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s nombre_d'elements\n", argv[0]);
        return 1;
    }
    uint64_t taille = atol(argv[1]);
    int32_t *tab = malloc(taille * sizeof(int32_t)); assert(tab);
    srandom(time(NULL));
    for (uint64_t i = 0; i < taille; i++) {
        tab[i] = (random() % 19) - 9;
    }
    if (taille < 20) {
        printf("Tableau initial : "); afficher_tab(tab, taille);
    }
    int32_t *sav =  malloc(taille * sizeof(int32_t)); assert(sav);
    int32_t *ref =  malloc(taille * sizeof(int32_t)); assert(ref);
    memcpy(sav, tab, sizeof(int32_t) * taille);
    clock_t debut = clock();
    qsort(tab, taille, sizeof(int32_t), comp);
    clock_t fin = clock();
    printf("Tri de reference : %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    memcpy(ref, tab, sizeof(int32_t) * taille);

    memcpy(tab, sav, sizeof(int32_t) * taille);
    debut = clock();
    tri_nain(tab, taille);
    fin = clock();
    if (taille < 20) {
        printf("Tableau trie par le nain : "); afficher_tab(tab, taille);
    }
    if (memcmp(ref, tab, sizeof(int32_t) * taille) == 0) {
        printf("Tri par le nain : %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    } else {
        printf("Erreur : le nain a mal trie le tableau (sale bete !)\n");
    }

    memcpy(tab, sav, sizeof(int32_t) * taille);
    debut = clock();
    tri_nain_opt(tab, taille);
    fin = clock();
    if (taille < 20) {
        printf("Tableau trie par le nain sous EPO : "); afficher_tab(tab, taille);
    }
    if (memcmp(ref, tab, sizeof(int32_t) * taille) == 0) {
        printf("Tri par le nain sous EPO : %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    } else {
        printf("Erreur : le nain fait vraiment n'importe-quoi !\n");
    }

    free(tab);
    free(sav);
    free(ref);
    return 0;
}

