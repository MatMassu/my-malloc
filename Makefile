VPATH = src #utils

#IDIR = utils 
CC=gcc
CFLAGS=-Wall -Wextra -g -fsanitize=address,undefined #-I$(IDIR) 
ODIR=obj
#UDIR= utils
#LDIR=lib

#_DEPS = utils.h
#DEPS = $(patsubst %, $(UDIR)/%,$(_DEPS))

_OBJ = main.o #utils.o 
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c #$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 
#$(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core