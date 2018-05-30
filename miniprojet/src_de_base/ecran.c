#include "cpu.h"
#include <inttypes.h>
#define MEM_VIDEO 0xB8000
#define PORT_CMD 0x3D4
#define PORT_DATA 0x3D5
#include "ecran.h"
#include <string.h>
uint32_t pos_x, pos_y;

// uint16_t *ptr_mem(uint32_t lig, uint32_t col)
// {
//     uint16_t *ptr;
//     ptr = ((uint16_t*)(MEM_VIDEO + 2 *( lig * 80 + col)));
//     return ptr;
// }


// void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t coul_texte, uint32_t coul_fond)
// {
//
//   *ptr_mem(lig,col)= c| (coul_texte<<8)| (coul_fond<<12);
//
// }

void efface_ecran(void)
{
  uint32_t lig, col;
 for (lig=0; lig<25;lig++){
   for (col=0; col<80;col++){
     ecrit_car(lig,col,' ',15,0);
   }
 }
}

// void place_curseur(uint32_t lig, uint32_t col){
//     pos_x=col;
//     pos_y=lig;
//    uint16_t pos  =col+lig*80;
//     outb(0x0F,PORT_CMD);
//     outb(pos, PORT_DATA);
//     outb(0x0E,PORT_CMD);
//     outb(pos>>8, PORT_DATA);
// }


void traite_car(char c){
  if (c>= 32 && c < 127)
  {
    if(pos_x==0 && pos_y==0)
      {
        ecrit_car(pos_y,pos_x,c,15,0);
        pos_x++;
      }
    else if (pos_x==79){
      place_curseur(pos_y+1,0);
      ecrit_car(pos_y,pos_x,c,15,0);
    }
    else{
      place_curseur(pos_y,pos_x+1);
      ecrit_car(pos_y,pos_x,c,15,0);
    }
  }
  else if(c <=31){
    switch(c)
    {
    case '\b':
          if((pos_x) != 0)
          {
          place_curseur(pos_y,pos_x-1);
          }
          break;
    case '\t':
        place_curseur(pos_y, (pos_x!=80-1)?((pos_x/8)*8+8):25-1 );
        break;
    case '\n':
      place_curseur(pos_y+1,0);
      break;
    case '\f':
        efface_ecran();
        place_curseur(0,0);
        break;
    case '\r':
      place_curseur(pos_y,0);
      break;
    }
  }
}

void defilement(void)
{
    memmove(ptr_mem(0, 0), ptr_mem(1, 0), 80 * 25 * 2);
    place_curseur(pos_y - 1, pos_x);
}

void console_putbytes(char *chaine, int32_t taille)
{
    for(int i = 0; i < taille; ++i){
        traite_car(chaine[i]);
    }
}
void affiche_haut_droite(char *chaine)
{
  uint32_t l = strlen(chaine);
  for(uint32_t i=0;i<=l;i++)
  {
    uint32_t pos = 80-l+i;
     ecrit_car(0, pos, chaine[i],15,0);
  }
}