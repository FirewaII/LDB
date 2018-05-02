#ifndef CR_TABLEHASH_H
#define CR_TABLEHASH_H

#include <stdbool.h>
#include <inttypes.h>

struct tablehash_t *nouv_tablehash(void);

bool est_vide_tablehash(struct tablehash_t *);

void afficher_tablehash(struct tablehash_t *);

void inserer_val_tablehash(uint8_t, struct tablehash_t *);

void supprimer_val_tablehash(uint8_t, struct tablehash_t *);

void detruire_tablehash(struct tablehash_t **);

#endif

