#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

struct cell_t {
    uint32_t val;
    struct cell_t *suiv;
    struct cell_t *prec;
};

struct liste_t {
    struct cell_t *tete;
    struct cell_t *queue;
};

// cette fonction contient un bug
// indice : faire un dessin et derouler l'execution sur 2 tours de boucle
struct liste_t *init_liste(uint32_t tab[], uint32_t taille)
{
    struct liste_t *liste = malloc(sizeof(struct liste_t)); assert(liste);
    liste->tete = malloc(sizeof(struct cell_t)); assert(liste->tete != NULL);
    liste->tete->prec = NULL;
    liste->queue = malloc(sizeof(struct cell_t)); assert(liste->queue != NULL);
    liste->queue->suiv = NULL;
    liste->tete->suiv = liste->queue;
    liste->queue->prec = liste->tete;
    for (uint32_t i = 0; i < taille; i++) {
        struct cell_t *cell = malloc(sizeof(struct cell_t)); assert(cell != NULL);
        cell->val = tab[i];
        cell->suiv = liste->queue;
        cell->prec = liste->tete;
        cell->prec->suiv = cell;
        liste->queue->prec = cell;
    }
    return liste;
}

// cette fonction ne contient pas de bug (connu !)
void affiche_liste(struct liste_t * liste, bool inv)
{
    struct cell_t *cour;
    struct cell_t *fin;
    if (inv) {
        cour = liste->queue->prec;
        fin = liste->tete;
        printf("  L' : "); fflush(stdout);
    } else {
        cour = liste->tete->suiv;
        fin = liste->queue;
        printf("  L  : "); fflush(stdout);
    }
    while (cour != fin) {
        printf("%" PRIu32 " <-> ", cour->val); fflush(stdout);
        cour = (inv) ? cour->prec : cour->suiv;
    }
    puts("Fin");
}

// cette fonction contient un bug
// indice : utilisez GDB pour tracer l'execution de cette fonction depuis
//   la fonction de tri ci-dessous
static void echange_cellules(struct cell_t *ptr)
{
    struct cell_t *prec, *cour, *suiv, *suiv_suiv;
    prec = ptr->prec;
    cour = ptr;
    suiv = ptr->suiv;
    suiv_suiv = suiv->suiv;
    prec->suiv = suiv;
    cour->prec = suiv;
    cour->suiv = suiv_suiv;
    suiv->prec = prec;
    suiv->suiv = cour;
    suiv_suiv->prec = cour;
    ptr = suiv;
}

// cette fonction contient deux bugs
// indice : l'un deux doit venir immediatement quand vous arrivez a ce point
// indice : pour le 2ème, GDB ou un dessin doivent vous aider 
void trie_liste(struct liste_t * liste)
{
    struct cell_t *cour;
    cour = liste->tete->suiv;
    while (cour->suiv != liste->queue) {
        if (cour->val > cour->suiv->val) {
            echange_cellules(cour);
            if (cour != liste->tete) {
                cour = cour->prec;
            }
        } else {
            cour = cour->suiv;
        }
    }
}

// cette fonction deux bugs "invisibles"
// indice : valgrind est votre ami !
void detruis_liste(struct liste_t **liste)
{
    struct cell_t *cour;
    cour = (*liste)->tete;
    while (cour != NULL) {
        free(cour);
        cour = cour->suiv;
    }
    *liste = NULL;
}

