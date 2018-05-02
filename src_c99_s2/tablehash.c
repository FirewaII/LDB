#include "liste.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define TAILLE_TABLE 4

struct tablehash_t {
    uint64_t nbr_elem;
    struct liste_t *table[TAILLE_TABLE];
};

static int64_t hash(uint8_t x)
{
    return x % TAILLE_TABLE;
}

struct tablehash_t *nouv_tablehash(void)
{
    // a changer
    // le compilateur genere aussi un avertissement si on
    //   declare une fonction et qu'on ne s'en sert jamais !
    (void)hash(0);
    return NULL;
}

bool est_vide_tablehash(struct tablehash_t *th)
{
    // a changer
    (void)th;
    return false;
}

void inserer_val_tablehash(uint8_t val, struct tablehash_t *th)
{
    // a completer
    (void)val;
    (void)th;
}

void supprimer_val_tablehash(uint8_t val, struct tablehash_t *th)
{
    // a completer
    (void)val;
    (void)th;
}

void afficher_tablehash(struct tablehash_t *th)
{
    // a completer
    (void)th;
}

void detruire_tablehash(struct tablehash_t **th)
{
    // a completer
    (void)th;
}

