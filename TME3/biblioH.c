#include "biblioH.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fonctionClef(char* auteur) {
    int res = 0;
    for (int i = 0; auteur[i]; i++) {
        res += (int)auteur[i];
    }
    return res;
}

LivreH* creer_livreH(int num, char* titre, char* auteur) {
    LivreH* res = (LivreH*)malloc(sizeof(LivreH));
    res->clef = fonctionClef(auteur);
    res->auteur = strdup(auteur);
    res->titre = strdup(titre);
    res->num = num;
    return res;
}

void liberer_livreH(LivreH* l) {
    free(l->auteur);
    free(l->titre);
    free(l);
}

BiblioH* creer_biblioH(int m) {
    if (m <= 0) {
        printf("Invalid hash table size.\n");
        return NULL;
    }
    BiblioH* res = (BiblioH*)malloc(sizeof(BiblioH));
    res->nE = 0;
    res->m = m;
    res->T = (LivreH**)malloc(m * sizeof(LivreH*));
    for (int i = 0; i < m; i++) {
        res->T[i] = NULL;
    }
    return res;
}

void liberer_biblioH(BiblioH* b) {
    if (!b) return;
    LivreH* curr;
    LivreH* tmp;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            tmp = curr->suiv;
            liberer_livreH(curr);
            curr = tmp;
        }
    }
    free(b->T);
    free(b);
}

int fonctionHachage(int cle, int m) {
    float A = (sqrt(5) - 1) / 2;
    return (int)(m * (cle * A - (int)(cle * A)));
}

void insererH(BiblioH* b, int num, char* titre, char* auteur) {
    LivreH* new = creer_livreH(num, titre, auteur);
    int hash = fonctionHachage(new->clef, b->m);
    new->suiv = b->T[hash];
    b->T[hash] = new;
    b->nE++;
}
