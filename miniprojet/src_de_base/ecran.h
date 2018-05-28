#define __ECRAN__
#include <inttypes.h>
#include <cpu.h>
#include <string.h>

uint32_t posX, posY;
uint32_t textColor, bgColor;



uint16_t *ptr_mem(uint32_t lig, uint32_t col);
void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond);
void efface_ecran(void);
void testAffiche();
void place_curseur(uint32_t lig, uint32_t col);
void traite_car(char c);        
void test_trait_car();
void test_stripes();
void defilement();
void console_putbytes(char* chaine, int32_t taille);
void set_default_colors();