BINS = pgcd somme mult lfsr

AS = gcc
ASFLAGS = -m64 -g -c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -m64 -g -std=gnu99
LD = gcc
LDFLAGS = -m64

OBJS = \
	   $(foreach f, $(BINS), $(addsuffix .o, $f)) \
	   $(foreach f, $(BINS), $(addprefix fct_, $(addsuffix .o, $f)))

.PHONY: all
all: $(BINS)

pgcd: pgcd.o fct_pgcd.o

somme: somme.o fct_somme.o

mult: mult.o fct_mult.o

lfsr: lfsr.o fct_lfsr.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

