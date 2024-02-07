#ifndef ENTREESORTIELC_H
#define ENTREESORTIELC_H

#include "biblioLC.h"

Biblio* charger_n_entrees(char* nom_fic, int n);
void enregistrer_biblio(Biblio* b, char* nom_fic);
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_num(Biblio* b, int num);



#endif
