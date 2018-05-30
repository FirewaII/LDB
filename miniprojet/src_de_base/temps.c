#include "temps.h"


uint32_t tayme = 0;
uint32_t compteur = 0;


void tic_PIT(void){
    
    char msg[9];
    outb(0x20, 0x20);
    uint32_t h, m, s;
    s = tayme % 60;
    m = ((tayme - s) % 3600) / 60;
    h = (tayme - m) / 3600;
    if (compteur == 50){
        compteur = 0;
        sprintf(msg, "%02d:%02d:%02d", h, m, s);
        affiche_haut_droite(msg); 
        tayme++;          
    }
    compteur++;
  
}

void init_traitant(void (*traitant)(void)){
    uint32_t *ad = (uint32_t*)(0x1000 + 2 * 4 * 32);
    *ad = ((KERNEL_CS & 0xFFFF) << 16) | (((uint32_t)(traitant) & 0xFFFF));
    *(ad + 1) = 0x8E00 | ((uint32_t)(traitant) & 0xFFFF0000);
}

void regle_freq(void){
    outb(0x34,0x43);
    outb((0x1234DD / 50) % 256, 0x40);
    outb((uint8_t)((0x1234DD / 50) >> 8), 0x40);
}

void unmask(uint32_t n_irq){
    uint8_t o;
    uint8_t mask;
    uint16_t port;
    if (n_irq < 8) {
        mask = 0xFF ^ (0x01 << n_irq);
        port = 0x21;
    } else {
        mask = 0xFF ^ (0x01 << (n_irq - 8));
        port =0xA1;
    }
    o = inb(port) & mask;
    o = o & mask;
    outb(o, port);
}