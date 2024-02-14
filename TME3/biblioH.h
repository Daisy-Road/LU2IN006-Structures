#ifndef BIBLIOH_H
#define BIBLIOH_H

typedef struct livreh {
    int clef;
    int num;
    char* titre;
    char* auteur;
    struct livreh* suiv;
} LivreH;

typedef struct table {
    int nE;
    int m;
    LivreH** T;
} BiblioH;

int fonctionClef(char* auteur);
LivreH* creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH* l);
BiblioH* creer_biblio(int m);
void liberer_biblio(BiblioH* b);
int fonctionHachage(int cle, int m);
void inserer(BiblioH* b, int num, char* titre, char* auteur);

#endif
