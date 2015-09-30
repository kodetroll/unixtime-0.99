#############################################
# 
# Simple makefile for unixtime utility
#
INSTALL=install
WHERE=~/bin
#IDIR =../include
CC=gcc
#CFLAGS=-I$(IDIR)
CFLAGS=-I.
LDFLAGS=-lm
DEPS = 
OBJS = unixtime.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: unixtime

unixtime: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core  

cleanall:
	rm -f *.o *~ core unixtime

install:
	$(INSTALL) -s unixtime $(WHERE)

