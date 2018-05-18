#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint8_t somme(void);

int main(void)
{
    printf("Somme(1 .. 10)  = %" PRIu8 "\n", somme());
    return 0;
}

