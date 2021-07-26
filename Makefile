##
# RRSS
#
# @file
# @version 0.1

CC=gcc
LFLAGS=-lncurses
OUTPUT=rrss

$(OUTPUT): rrss.o feed.o render.o
	$(CC) -o $(OUTPUT) feed.o render.o rrss.o $(LFLAGS)
rrss.o: feed.h render.h rrss.c
	$(CC) -c -o rrss.o rrss.c
render.o: feed.h render.h render.c
	$(CC) -c -o render.o render.c
feed.o: feed.h feed.c
	$(CC) -c -o feed.o feed.c
clean:
	rm *.o rrss
