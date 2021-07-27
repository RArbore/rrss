##
# RRSS
#
# @file
# @version 0.1

CC=gcc
LFLAGS=-lncurses -lcurl
OUTPUT=rrss

$(OUTPUT): rrss.o feed.o render.o keyboard.o
	$(CC) -o $(OUTPUT) feed.o render.o keyboard.o rrss.o $(LFLAGS)
rrss.o: feed.h render.h keyboard.h rrss.c
	$(CC) -c -o rrss.o rrss.c
keyboard.o: render.h keyboard.h keyboard.c
	$(CC) -c -o keyboard.o keyboard.c
render.o: feed.h render.h render.c
	$(CC) -c -o render.o render.c
feed.o: feed.h feed.c
	$(CC) -c -o feed.o feed.c
clean:
	rm *.o rrss
