BINS = testliste testtablehash
MODS = liste tablehash

CC = gcc
CFLAGS = -m64 -std=gnu99 -g -Wall -Wextra -Werror
LD = gcc
LDFLAGS = -m64

OBJS = $(foreach f, $(BINS), $(addsuffix .o, $f)) \
	   $(foreach f, $(MODS), $(addsuffix .o, $f))

.PHONY: all
all: $(BINS)

testliste: testliste.o liste.o

testtablehash: testtablehash.o tablehash.o liste.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

