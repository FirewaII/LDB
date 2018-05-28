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
    set_default_colors();    
    for (uint32_t i = 0; i< 25; i++){
        for (uint32_t j = 0; j< 79; j++){
            ecrit_car(i, j, ' ', textColor, bgColor);
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

void test_trait_car()
{
    traite_car('T');        
    traite_car('E');        
    traite_car('S');        
    traite_car('T');
    traite_car('\n');
    traite_car('J');        
    traite_car('E');        
    traite_car('R');        
    traite_car('B');        
    traite_car('\b');
    traite_car('S');
    traite_car('H');
    traite_car('\t');
    traite_car('A');
    traite_car('A');
    traite_car('\n');
    traite_car('\n');
    traite_car('\n');
    traite_car('\n');
    traite_car('L');
    traite_car('F');
    traite_car('\f');
    traite_car('M');
    traite_car('S');
    traite_car('\r');
    traite_car('A');
    traite_car('A');
}
/*
void place_curseur(uint32_t lig, uint32_t col)
{
    // pos= col + lig × 80
    uint16_t pos = col + lig * 80;
    // 7 -> 0
    outb(0x0F,0x3D4);    
    outb(pos, 0x3D5);
    // 15 -> 8
    outb(0x0E, 0x3D4);
    outb(pos << 8, 0x3D5);
}
*/
void traite_car(char c)
{
    if ( c < 0 || c > 127){
        return;
    }
    else{
        switch (c){
            case 8:
                if (posX > 0){
                    posX--;
                }
                break;
            case 9:
                posX = ((posX / 8) + 1) * 8;
                if (posX > 79){
                    posX = 79;
                }
                break;
            case 10:
                posX = 0;
                posY++;
                break;
            case 12:
                efface_ecran();
                posX = 0;
                posY = 0;
                break;
            case 13:
                posX = 0;
                break;
            default:
                ecrit_car(posY, posX, c, textColor, bgColor);
                if (posX > 79){
                    if (posY > 24){
                        defilement();
                    }else{
                        posY++; 
                        posX=0;
                    }
                } else {
                    posX++;
                }
        }
        if (posY > 24){
            defilement();
        }
        place_curseur(posY, posX);        
    }
}

void test_stripes()
{
    uint32_t bg1, bg2;
    bg1 = 2;
    bg2 = 4;
    efface_ecran();
    for (uint32_t i = 0; i< 30; i++){
        for (uint32_t j = 0; j< 80; j++){
            if (i%2 == 0){
                ecrit_car(i, j, ' ', 0, bg1);
            } else {
                ecrit_car(i, j, ' ', 0, bg2);
            }
        }
    }
}
void defilement(void)
{
    // move every line to the previous
    // line 0 is not moved
    memmove(ptr_mem(0, 0), ptr_mem(1, 0), 4000);
}

void console_putbytes(char* chaine, int32_t taille)
{

    for (int32_t i = 0; i < taille; i++){
        traite_car(chaine[i]);
    }
}

void set_default_colors()
{
    textColor = 15;
    bgColor = 0;
}