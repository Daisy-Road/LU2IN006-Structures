#include "tab.h"

#include <stdlib.h>
#include <stdio.h>

int* alloue_tableau(int n) {
    // Cette solution est la meilleure car elle évite de perdre le pointeur
    // de T si jamais il a été associé.
    return malloc(n*sizeof(int));
}

void desalloue_tableau(int* tab) { free(tab); }

void remplir_tableau(int* tab, int size, int max) {
    for(int i=0; i<size; i++) {
        tab[i] = rand()%max;
    }
}

void afficher_tableau(int* tab, int size) {
    printf("tab = [");
    for(int i=0; i<size; i++) {
        printf("%d", tab[i]);
        if(i != size-1) printf(", ");
    }
    printf("]\n");

}

int power(int a, int b) {
    for(int i = 1; i<b; i++) a*=a;
    return a;
}

int sumOn2(int* tab, int size) {
    int res = 0;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            res += power(tab[i] - tab[j], 2); 
        }
    }
    return res;
}

int sumOn(int* tab, int size) {
    int x=0;
    int y=0;
    for(int i=0; i<size; i++) {
        x+=power(tab[i], 2);
        y+=tab[i];
    }
    return 2*(size*x - y*y);
}
