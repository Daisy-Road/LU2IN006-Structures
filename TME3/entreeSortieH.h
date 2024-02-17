#ifndef IOH_H
#define IOH_H

#include "biblioH.h"

BiblioH* charger_n_entrees(char* nom_fic, int n);
void enregistrer_biblio(BiblioH* b, char* nom_fic);
void afficher_livre(LivreH* l);
void afficher_biblio(BiblioH* b);
LivreH* recherche_num(BiblioH* b, int num);
LivreH* recherche_titre(BiblioH* b, char* titre);

#endif
