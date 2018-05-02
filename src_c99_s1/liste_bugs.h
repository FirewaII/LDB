#ifndef CR_LISTE_BUGS_H
#define CR_LISTE_BUGS_H

#include <stdbool.h>
#include <inttypes.h>

struct liste_t *init_liste(uint32_t[], uint32_t);

void affiche_liste(struct liste_t *, bool);

void detruis_liste(struct liste_t **);

void trie_liste(struct liste_t *);

#endif

