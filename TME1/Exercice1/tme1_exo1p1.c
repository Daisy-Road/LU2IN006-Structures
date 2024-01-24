#include<stdio.h>
#include<stdlib.h>

const static int len = 10;

int main(void) {
    int *tab;
    unsigned int i;

    tab = (int*)malloc(len*sizeof(int));

    for (i=len-1; i>=0; i--) {
        tab[i] = i;
    }

    free(tab);
    return 0;
}

// Q.1.1: Le program fait un segfault

// Q.1.2 et 3: La valeur de i après i=0 devient 4'294'967'295 qui est la valeur maximal d'un unsigned int (car -1 n'est pas positif).
// Ainsi, on tente d'accéder à l'index 4294967295 de tab à la prochaine itération.
// C'est ce qui cause l'erreur. Pour la corriger, remplaçon l'inégalité large par une inégalité stricte
// Dans la condition de boucle.
