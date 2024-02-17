#ifndef IOH_H
#define IOH_H

#include "biblioH.h"

BiblioH* charger_n_entrees(char* nom_fic, int n);
void enregistrer_biblio(BiblioH* b, char* nom_fic);
void afficher_livre(LivreH* l);
void afficher_biblio(BiblioH* b);
LivreH* recherche_num(BiblioH* b, int num);
LivreH* recherche_titre(BiblioH* b, char* titre);
BiblioH* recherche_auteur(BiblioH* b, char* auteur);
void suppression_num(BiblioH* b, int num);
void suppression_titre(BiblioH* b, char* titre);
void suppression_auteur(BiblioH* b, char* auteur);
void suppression_ouvrage(BiblioH* b, int num, char* titre, char* auteur);
void fusion(BiblioH* b1, BiblioH* b2);
void supprimer_doublons(BiblioH* b);
#endif
