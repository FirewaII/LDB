BINS = main matrice abr

AS = gcc
ASFLAGS32 = -m32 -g -c
ASFLAGS = -m64 -g -c
CC = gcc
CFLAGS32 = -Wall -Wextra -Werror -m32 -g -std=gnu99
CFLAGS = -Wall -Wextra -Werror -m64 -g -std=gnu99
LD = gcc
LDFLAGS32 = -m32
LDFLAGS = -m64

OBJS = \
	   $(foreach f, $(BINS), $(addsuffix .o, $f)) \
	   $(foreach f, $(BINS), $(addprefix fct_, $(addsuffix .o, $f)))

.PHONY: all
all: $(BINS)

main: main.o

matrice: matrice.o fct_matrice.o
	$(LD) $(LDFLAGS32) -o $@ $^

matrice.o: matrice.c
	$(CC) $(CFLAGS32) -o $@ -c $<

fct_matrice.o: fct_matrice.s
	$(AS) $(ASFLAGS32) -o $@ $<

abr: abr.o fct_abr.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

