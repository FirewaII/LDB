BINS = struct progbug liste

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

struct: struct.o fct_struct.o

liste: liste.o fct_liste.o

progbug: progbug.o fct_progbug.o

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

