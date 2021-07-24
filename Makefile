##
# RRSS
#
# @file
# @version 0.1

CC=gcc
LFLAGS=-lncurses
OUTPUT=rrss

$(OUTPUT): rrss.o feed.o
	$(CC) -o $(OUTPUT) feed.o rrss.o $(LFLAGS)
rrss.o: feed.h rrss.c
	$(CC) -c -o rrss.o rrss.c
feed.o: feed.h feed.c
	$(CC) -c -o feed.o feed.c
clean:
	rm *.o rrss
