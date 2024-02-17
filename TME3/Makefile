CC=gcc
PROGRAMS=main.out mainH.out

all: $(PROGRAMS)

biblioLC.o: biblioLC.c
	$(CC) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c entreeSortieLC.c

main.o: main.c
	$(CC) -c main.c

main.out: biblioLC.o entreeSortieLC.o main.o
	$(CC) biblioLC.o entreeSortieLC.o main.o -o main.out

biblioH.o: biblioH.c
	$(CC) -c biblioH.c

entreeSortieH.o: entreeSortieH.c
	$(CC) -c entreeSortieH.c

mainH.o: mainH.c
	$(CC) -c mainH.c

mainH.out: biblioH.o entreeSortieH.o mainH.o
	$(CC) biblioH.o entreeSortieH.o mainH.o -o mainH.out

clean:
	rm -f $(PROGRAMS) *.o
