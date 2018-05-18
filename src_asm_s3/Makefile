BINS = pgcd fact age fibo mult palin tri_nain val_bin

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

fact: fact.o fct_fact.o

age: age.o fct_age.o

fibo: fibo.o fct_fibo.o

mult: mult.o fct_mult.o

palin: palin.o fct_palin.o

tri_nain: tri_nain.o fct_tri_nain.o

val_bin: val_bin.o fct_val_bin.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

