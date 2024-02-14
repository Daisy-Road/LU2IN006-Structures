#include "entreeSortieH.h"
#include "biblioH.h"

#include <stdio.h>

#define MAX_BUFFER_SIZE 256

BiblioH* charger_n_entrees(char* nom_fic, int n) {
    FILE* f = fopen(nom_fic, "r");
    if(!f) return NULL;
    BiblioH* b = creer_biblio(n);
    int num;
    char auteur[MAX_BUFFER_SIZE];
    char titre[MAX_BUFFER_SIZE];
    for(int i = 0; i<n; i++) {
        fscanf(f, "%d %s %s\n", &num, titre, auteur);    
        inserer(b, num, titre, auteur);
    }
    return b;
}

void enregistrer_biblio(BiblioH* b, char* nom_fic) {
    FILE* f = fopen(nom_fic, "w");
    if(!f) return;
    LivreH* curr;
    for(int i=0; i<b->m; i++) {
        curr = b->T[i];
        while(curr) {
            fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
            curr = curr->suiv;
        }
    }
}

void afficher_livre(LivreH* l) {
   printf("Livre %d (%d): \"%s\" %s", l->num, l->clef, l->titre, l->auteur); 
}
