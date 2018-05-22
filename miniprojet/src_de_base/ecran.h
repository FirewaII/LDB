#define __ECRAN__
#include <inttypes.h>
#include <cpu.h>

uint32_t posX, posY;




uint16_t *ptr_mem(uint32_t lig, uint32_t col);
void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond);
void efface_ecran(void);
void testAffiche();
void place_curseur(uint32_t lig, uint32_t col);
void traite_car(char c);