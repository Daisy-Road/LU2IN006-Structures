#include "mat.h"

#include <stdlib.h>
#include <stdio.h>

int* alloue_matrice(int n) {
    return malloc(n*n*sizeof(int));
}

void desalloue_matrice(int* mat) { free(mat); }

void remplir_matrice(int* mat, int size, int max) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            mat[MAT(i, j, size)] = rand()%max;
        }
    }
}

void afficher_matrice(int* mat, int size) {
    for(int j=0; j<size; j++) {
        printf("[");
        for(int i=0; i<size; i++) {
            printf("%d", mat[MAT(i,j,size)]);
            if(i != size-1) printf(" ");
        }
        printf("]\n");
    }
}
