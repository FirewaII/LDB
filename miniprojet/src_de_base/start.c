#include <cpu.h>
#include <inttypes.h>
#include <ecran.h>

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
    //uint32_t x = fact(5);
    // quand on saura gerer l'ecran, on pourra afficher x
    //(void)x;
    // on ne doit jamais sortir de kernel_start
    while (1) {
        // cette fonction arrete le processeur
        //testAffiche();
        //place_curseur(17, 9);
        efface_ecran();
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
        hlt();
    }
}

