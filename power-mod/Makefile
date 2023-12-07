CC = gcc
CFLAGS = -Werror -Wall -Wpedantic -g

all: power-mod

power-mod: find-remainder-bf.o find-remainder-dp.o power-mod.c
	$(CC) $(CFLAGS) *.o power-mod.c -o power-mod

find-remainder-bf.o: find-remainder-bf.c
	$(CC) $(CFLAGS) -c find-remainder-bf.c 

find-remainder-dp.o: find-remainder-dp.c
	$(CC) $(CFLAGS) -c find-remainder-dp.c 

clean:
	rm *.o power-mod