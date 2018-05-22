#include <ecran.h>


/*uint16_t *ptr_mem(uint32_t lig, uint32_t col)
{
    return (uint16_t*) (0xB8000 + 2 * (lig * 80 + col));
}

void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond)
{
    *ptr_mem(lig, col) = c | (coul_texte << 8) | (coul_fond << 12);
}*/

void efface_ecran(void)
{
    for (uint32_t i = 0; i< 80; i++){
        for (uint32_t j = 0; j< 25 ; j++){
            ecrit_car(i, j, ' ', 0, 0);
        }
    }
}

void testAffiche()
{
    //efface_ecran();
    ecrit_car(0, 0, 'K', 8, 0);
    ecrit_car(20, 7, 'a', 3, 0);
    ecrit_car(10, 15, 'Y', 5, 6);
    ecrit_car(24, 79, 'Z', 15, 0);
    ecrit_car(24, 0, 'A', 15, 0);
    ecrit_car(0, 79, 'B', 15, 0);
}

/*void place_curseur(uint32_t lig, uint32_t col)
{
    // pos= col + lig × 80
    uint16_t pos = col + lig * 80;
    // 7 -> 0
    outb(0x0F,0x3D4);    
    outb(pos && 0xFF00, 0x3D5);
    // 15 -> 8
    outb(0x0E, 0x3D4);
    outb(pos && 0x00FF, 0x3D5);
}*/