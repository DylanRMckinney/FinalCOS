CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: FinalCOS

FinalCOS: FinalCOS.o roomFuncs.o
	$(CC) $(CFLAGS) -o FinalCOS FinalCOS.o roomFuncs.o

FinalCOS.o: FinalCOS.c roomFuncs.h
	$(CC) $(CFLAGS) -c FinalCOS.c

roomFuncs.o: roomFuncs.c roomFuncs.h
	$(CC) $(CFLAGS) -c roomFuncs.c

clean:
	rm -f *.o FinalCOS