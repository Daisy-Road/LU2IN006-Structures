#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* alloue_tableau(int n){
    int* tab=(int*)malloc(sizeof(int)*n);
    return tab;
}

void desalloue_tableau(int* tab) {free(tab);}

void remplir_tableau(int* tab, int n, int v) {
    for(int i=0; i<n;i++) {
        tab[i] = rand()%(v);
    }
} 

void afficher_tableau(int* tab, int n) {
    printf("tab = [");
    for(int i = 0; i<n; i++) {
        printf("%d", i);
        if(i != n) printf(", ");
    }
    printf("]\n");
}