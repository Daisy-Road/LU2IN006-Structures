#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Livre* creer_livre(int num, char* titre, char* auteur) {
    /* Alloue l'espace pour un livre portant le numéro "num",
     * titré "titre" et écrit par "auteur" */
    Livre* res = (Livre*)malloc(sizeof(Livre));
    res->num = num;
    res->titre = strdup(titre);
    res->auteur = strdup(auteur);
    return res;
}

void liberer_livre(Livre* l) {
    /* Libère l'ensemble du bloc "l" */
    free(l->titre);
    free(l->auteur);
    free(l);
}

Biblio* creer_biblio() {
    /* Alloue l'espace nécéssaire pour une bibliothèque */
    Biblio* res = (Biblio*)malloc(sizeof(Biblio));
    res->L = NULL;
    return res;
}

void liberer_biblio(Biblio* b) {
    /* Libère l'intégralité de la bibliothèque "b":
     * L'ensemble de ses livres et le bloc "b" */
    Livre* curr = b->L;
    Livre* tmp = NULL;
    while (curr) {
        tmp = curr;
        curr = curr->suiv;
        liberer_livre(tmp);
    }
    free(b);
}

void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur) {
    /* Alloue l'espace pour un nouveau livre de numéro "num", titré "titre"
     * et écrit par "auteur" et l'ajoute en tête de liste de "b" */
    Livre* new = creer_livre(num, titre, auteur);
    new->suiv = b->L;
    b->L = new;
}
