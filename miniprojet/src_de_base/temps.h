#include "segment.h"
#include "ecran.h"
#include <inttypes.h>
#include <stdio.h>
#include "cpu.h"

void tic_PIT(void);
void regle_freq(void);
void init_traitant(void (*traitant)(void));
void traitant_IT_32();
void unmask(uint32_t it);