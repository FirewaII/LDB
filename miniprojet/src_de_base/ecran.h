#ifndef __START_H__
#define __START_H__
#include <inttypes.h>

uint16_t *ptr_mem(uint32_t lig, uint32_t col);
void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond);
void efface_ecran(void);
void place_curseur(uint32_t lig, uint32_t col) ;
void traite_car(char c);
void affiche_haut_droite(char *chaine);

#endif