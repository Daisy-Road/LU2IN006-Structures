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
LivreH* creer_livreH(int num, char* titre, char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle, int m);
void insererH(BiblioH* b, int num, char* titre, char* auteur);

#endif
