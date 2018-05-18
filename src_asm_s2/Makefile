BINS = chaines tableaux

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

chaines: chaines.o fct_chaines.o

tableaux: tableaux.o fct_tableaux.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

