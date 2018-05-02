#ifndef CR_LISTE_H
#define CR_LISTE_H

#include <stdbool.h>
#include <inttypes.h>

struct liste_t *nouv_liste(void);

bool est_vide_liste(struct liste_t *);

void inserer_tete_liste(uint8_t, struct liste_t *);

void afficher_liste(struct liste_t *);

bool supprimer_val_liste(uint8_t, struct liste_t *);

void detruire_liste(struct liste_t **);

#endif

