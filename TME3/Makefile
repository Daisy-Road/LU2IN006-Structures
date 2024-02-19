CC=gcc
PROGRAMS=main.out mainH.out comparaison.out

all: $(PROGRAMS)

biblioLC.o: biblioLC.c
	$(CC) -c biblioLC.c -Wall

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c entreeSortieLC.c -Wall

main.o: main.c
	$(CC) -c main.c

main.out: biblioLC.o entreeSortieLC.o main.o
	$(CC) biblioLC.o entreeSortieLC.o main.o -o main.out -Wall

biblioH.o: biblioH.c
	$(CC) -c biblioH.c -Wall

entreeSortieH.o: entreeSortieH.c
	$(CC) -c entreeSortieH.c -Wall

mainH.o: mainH.c
	$(CC) -c mainH.c -Wall

mainH.out: biblioH.o entreeSortieH.o mainH.o
	$(CC) biblioH.o entreeSortieH.o mainH.o -o mainH.out -Wall

comparaison.o: comparaison.c
	$(CC) -c comparaison.c

comparaison.out: biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o comparaison.o
	$(CC) biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o comparaison.o -o comparaison.out -Wall

clean:
	rm -f $(PROGRAMS) *.o
