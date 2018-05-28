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
    set_default_colors(); 
    while (1) {
        // cette fonction arrete le processeur
        efface_ecran();
        test_stripes();
        //defilement();
        console_putbytes("BONJOUR", 7);
        /*console_putbytes("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\tExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 449);*/
        hlt();
    }
}

