#ifndef IOH_H
#define IOH_H

#include "biblioH.h"

BiblioH* charger_n_entreesH(char* nom_fic, int n, int size);
void enregistrer_biblioH(BiblioH* b, char* nom_fic);
void afficher_livreH(LivreH* l);
void afficher_biblioH(BiblioH* b);
LivreH* recherche_numH(BiblioH* b, int num);
LivreH* recherche_titreH(BiblioH* b, char* titre);
BiblioH* recherche_auteurH(BiblioH* b, char* auteur);
void suppression_numH(BiblioH* b, int num);
void suppression_titreH(BiblioH* b, char* titre);
void suppression_auteurH(BiblioH* b, char* auteur);
void suppression_ouvrageH(BiblioH* b, int num, char* titre, char* auteur);
void fusionH(BiblioH* b1, BiblioH* b2);
void supprimer_doublonsH(BiblioH* b);

#endif
