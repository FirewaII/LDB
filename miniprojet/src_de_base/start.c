#include "cpu.h"
#include <inttypes.h>
#include "ecran.h"
#include <stdio.h>
#include "stdlib.h"
#include "temps.h"
// on peut s'entrainer a utiliser GDB avec ce code de base
// par exemple afficher les valeurs de x, n et res avec la commande display

// une fonction bien connue
uint32_t fact(uint32_t n)
{
    uint32_t res;
    if (n <= 1) {
        res = 1;
    } else {
        res = fact(n - 1) * n;
    }
    return res;
}

void kernel_start(void)
{
    regle_freq();
    init_traitant(traitant_IT_32);
    unmask(0);
    sti();    
    while (1) {
        // cette fonction arrete le processeur
        hlt();
    }
}