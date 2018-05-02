#include "liste.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // la fonction srandom initialise le generateur de
    //   nombres aleatoires
    srandom(time(NULL));
    // ensuite, on utilise random() pour recuperer une valeur
    //   aleatoire entre 0 et une valeur max tres grande
    // si on veut par exemple recuperer des entiers entre 0 et
    //   9, on utilisera un modulo : random() % 10
    // a completer
    return 0;
}

