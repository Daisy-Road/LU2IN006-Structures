#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Livre* creer_livre(int num, char* titre, char* auteur) {
    Livre* res = (Livre*)malloc(sizeof(Livre));
    res->num = num;
    res->titre = strdup(titre);
    res->auteur = strdup(auteur);
    return res;
}

void liberer_livre(Livre* l) { 
    free(l->titre);
    free(l->auteur);
    free(l); 
}

Biblio* creer_biblio() {
    Biblio* res = (Biblio*) malloc(sizeof(Biblio));
    res->L = NULL;
    return res;
}

void liberer_biblio(Biblio* b) {
    Livre* curr = b->L;
    Livre* tmp = NULL;
    while(curr) {
        tmp =curr;
        curr = curr->suiv;
        liberer_livre(tmp);
    }
    free(b);
}

void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur) {
    Livre* new = creer_livre(num, titre, auteur);
    new->suiv = b->L;
    b->L = new;
}


