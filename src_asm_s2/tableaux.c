
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define TAILLE_MAX 1000000

uint64_t taille;

int32_t tab[TAILLE_MAX];

void tri_min(void);
void tri_min_opt(void);

void afficher_tab(void)
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
    taille = atol(argv[1]);
    srandom(time(NULL));
    for (uint32_t i = 0; i < taille; i++) {
        tab[i] = (random() % 19) - 9;
    }
    if (taille < 20) {
        printf("Tableau initial : "); afficher_tab();
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
    tri_min();
    fin = clock();
    if (taille < 20) {
        printf("Tableau trie par recherche du minimum : "); afficher_tab();
    }
    if (memcmp(ref, tab, sizeof(int32_t) * taille) == 0) {
        printf("Tri par recherche du minimum : %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    } else {
        printf("Erreur : le tri par recherche du minimum n'est pas correct !\n");
    }

    memcpy(tab, sav, sizeof(int32_t) * taille);
    debut = clock();
    tri_min_opt();
    fin = clock();
    if (taille < 20) {
        printf("Tableau trie par recherche du minimum optimise : "); afficher_tab();
    }
    if (memcmp(ref, tab, sizeof(int32_t) * taille) == 0) {
        printf("Tri par recherche du minimum optimise : %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    } else {
        printf("Erreur : le tri par recherche du minimum optimise n'est pas correct !\n");
    }

    free(sav);
    free(ref);
    return 0;
}

