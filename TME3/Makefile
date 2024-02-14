CC=gcc

all: main.out

biblioLC.o: biblioLC.c
	$(CC) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c entreeSortieLC.c

main.o: main.c
	$(CC) -c main.c

main.out: biblioLC.o entreeSortieLC.o main.o
	$(CC) biblioLC.o entreeSortieLC.o main.o -o main.out

clean:
	rm -f main.out *.o
