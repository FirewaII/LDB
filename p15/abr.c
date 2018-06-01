#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

// nombre d'elements dans l'arbre
#define NBR_ELEM 9

// le type d'un noeud de l'arbre
struct noeud_t {
    uint64_t val;       // valeur du noeud
    struct noeud_t *fg; // fils gauche
    struct noeud_t *fd; // fils droite
};

// renvoie vrai ssi la valeur est presente dans l'arbre
bool est_present(uint64_t, struct noeud_t *);

// copie les valeurs des noeuds de l'arbre dans un tableau
// le tableau n'est pas passé en argument : il s'agit d'une variable globale
void abr_vers_tab(struct noeud_t *);

// cree un noeud en allouant l'espace memoire et en
//   initialisant les champs de la structure
struct noeud_t *cree_noeud(uint64_t val, struct noeud_t *fg,
                           struct noeud_t *fd)
{
    struct noeud_t *res = malloc(sizeof(struct noeud_t));
    assert(NULL != res);
    res->val = val;
    res->fg = fg;
    res->fd = fd;
    return res;
}

// cree l'ABR donne dans l'enonce
struct noeud_t *abr_enonce(void)
{
    return cree_noeud(8,
               cree_noeud(3,
                   cree_noeud(1, NULL, NULL),
                   cree_noeud(6,
                       cree_noeud(4, NULL, NULL),
                       cree_noeud(7, NULL, NULL))),
               cree_noeud(10, NULL,
                   cree_noeud(14,
                   cree_noeud(13, NULL, NULL),
                       NULL)));
}

// teste la presence de valeurs entre 0 et 14 dans l'arbre
void test_presence(struct noeud_t *abr)
{
    for (uint64_t i = 0; i < 15; i++) {
        printf("est_present(%" PRIu64 ", abr) ? : %s\n",
                i, est_present(i, abr) ? "oui" : "non");
    }
    puts("");
}

// une fonction d'affichage du tableau
void affiche_tab(uint64_t tab[])
{
    printf("Contenu du tableau : ");
    for (uint32_t i = 0; i < NBR_ELEM; i++) {
        printf("%" PRIu64 " ", tab[i]);
    }
    puts("");
}

// cette variable doit etre implantee dans le fichier assembleur
extern uint64_t *ptr;

// fonction principale
int main(void)
{
    // deux arbres, un vide et un plein
    struct noeud_t *abr_vide, *abr_ex;

    // cree un arbre vide
    abr_vide = NULL;
    // teste la presence de valeurs dans cet arbre
    puts("Presence des valeurs dans l'arbre vide :");
    test_presence(abr_vide);

    //  cree l'arbre de l'enonce
    abr_ex = abr_enonce();
    // teste la presence de valeur dans cet arbre
    puts("Presence des valeurs dans l'arbre de l'enonce :");
    test_presence(abr_ex);

    // cree un tableau
    uint64_t tab[NBR_ELEM];
    // initialise le ptr sur la premiere case du tableau
    ptr = tab;
    // copie les elements de l'arbre dans le tableau
    abr_vers_tab(abr_ex);
    // affiche le tableau
    affiche_tab(tab);

    return 0;
}

