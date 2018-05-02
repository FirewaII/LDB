#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>

struct cell_t {
    uint8_t val;
    struct cell_t *suiv;
};

struct liste_t {
    struct cell_t tete;
};

struct liste_t *nouv_liste(void)
{
    //struct cell_t tete = malloc(sizeof(cell_t));
    struct liste_t *liste = malloc(sizeof(struct liste_t));
    liste->tete.suiv = NULL;
    return liste;
}

bool est_vide_liste(struct liste_t *liste)
{
    // a changer

    // le compilateur genere un avertissement si on n'utilise
    //   pas un parametre ou une variable declare
    // pour eviter ca, il suffit de le transtyper vers void
    //(void)liste;
    if (liste == NULL || liste->tete.suiv == NULL){
      return true;
    }
    return false;
}

void inserer_tete_liste(uint8_t val, struct liste_t *liste)
{
    // a completer
    struct cell_t *newCell = malloc(sizeof(struct cell_t));
    newCell->val = val;
    if (liste->tete.suiv != NULL){
      newCell->suiv = liste->tete.suiv;
    } else{
      newCell->suiv = NULL;
    }
    liste->tete.suiv = newCell;
}

bool supprimer_val_liste(uint8_t val, struct liste_t *liste)
{
    // a changer
    if (est_vide_liste(liste)){
      return false;
    }
    struct cell_t *cur = &(liste->tete);
    struct cell_t *last;
    // Tant qu'il existe un suivant
    while (cur->suiv){
      // On garde la valeur actuel dans last
      last = cur;
      // S'il s'agit de la valeur recherchée
      if (cur->val == val){
        // Le suiv de la cell courante devient le suiv de la cell qui precede
        last->suiv = cur->suiv;
        // Libere la memoire
        free(cur);
        return true;
      }
      // On se deplace de +1
      cur = cur->suiv;
    }
    return false;
}

void afficher_liste(struct liste_t *liste)
{
  if (est_vide_liste(liste)){
    return;
  }
  struct cell_t *cur = &(liste->tete);
  while (cur->suiv){
    //strVal = (char)cur.val;
    printf("%" PRIu8 "\n", cur->val);
    cur = cur->suiv;
  }
}

void detruire_liste(struct liste_t **liste)
{
  if (liste==NULL){
    return;
  }
  else if ((*liste) == NULL){
    free(liste);
    return;
  }
  else{
    struct cell_t *cur = &((*liste)->tete);
    struct cell_t *next;
    while (cur->suiv){
      if (cur->suiv->suiv != NULL){
        next = cur->suiv->suiv;

      }
      cur = cur->suiv;
    }
    free(liste);
  }
}
