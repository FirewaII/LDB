BINS = align fact palin tri_nain liste

AS = gcc
ASFLAGS = -m32 -g -c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -m32 -g -std=gnu99
LD = gcc
LDFLAGS = -m32

OBJS = \
	   $(foreach f, $(BINS), $(addsuffix .o, $f)) \
	   $(foreach f, $(BINS), $(addprefix fct_, $(addsuffix .o, $f)))

.PHONY: all
all: $(BINS)

align: align.o fct_align.o

liste: liste.o fct_liste.o

tri_nain: tri_nain.o fct_tri_nain.o

fact: fact.o fct_fact.o

palin: palin.o fct_palin.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

