#ifndef ENTREESORTIELC_H
#define ENTREESORTIELC_H

#include "biblioLC.h"

Biblio* charger_n_entrees(char* nom_fic, int n);
void enregistrer_biblio(Biblio* b, char* nom_fic);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_num(Biblio* b, int num);
Livre* recherche_titre(Biblio* b, char* titre);
Biblio* recherche_auteur(Biblio* b, char* auteur);
void suppression_num(Biblio* b, int num);
void suppression_titre(Biblio* b, char* titre);
void suppression_auteur(Biblio* b, char* auteur);
void suppression_livre(Biblio* b, int num, char* titre, char* auteur);
void fusion_biblio(Biblio* b1, Biblio* b2);
Biblio* recherche_doublons(Biblio* b);



#endif
