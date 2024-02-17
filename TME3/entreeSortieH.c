#include "entreeSortieH.h"
#include "biblioH.h"

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

BiblioH* charger_n_entrees(char* nom_fic, int n) {
    FILE* f = fopen(nom_fic, "r");
    if (!f) return NULL;
    BiblioH* b = creer_biblio(n);
    int num;
    char auteur[MAX_BUFFER_SIZE];
    char titre[MAX_BUFFER_SIZE];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %s %s\n", &num, titre, auteur);
        inserer(b, num, titre, auteur);
    }
    return b;
}

void enregistrer_biblio(BiblioH* b, char* nom_fic) {
    FILE* f = fopen(nom_fic, "w");
    if (!f) return;
    LivreH* curr;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
            curr = curr->suiv;
        }
    }
}

void afficher_livre(LivreH* l) {
    printf("Livre %d (%d): \"%s\" de %s", l->num, l->clef, l->titre, l->auteur);
}

void afficher_biblio(BiblioH* b) {
    printf("------ [ Bibliotheque ] ------\n");
    LivreH* curr;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            afficher_livre(curr);
            curr = curr->suiv;
        }
    }
    printf("------------------------------\n");
}

LivreH* recherche_num(BiblioH* b, int num) {
    LivreH* curr;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            if (curr->num == num) return curr;
            curr = curr->suiv;
        }
    }
    return NULL;
}

LivreH* recherche_titre(BiblioH* b, char* titre) {
    LivreH* curr;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            if (strcmp(curr->titre, titre) == 0) return curr;
            curr = curr->suiv;
        }
    }
    return NULL;
}

BiblioH* recherche_auteur(BiblioH* b, char* auteur) {
    BiblioH* res = creer_biblio(1);
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    LivreH* curr = b->T[index];
    while (curr) {
        if (strcmp(curr->auteur, auteur) == 0)
            inserer(b, curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }
    return res;
}

void suppression_num(BiblioH* b, int num) {
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            nxt = curr->suiv;
            if (curr->num == num) {
                if (prev) prev->suiv = nxt;
                else b->T[i] = nxt;
                liberer_livre(curr);
            } else prev = curr; // No element removed, previous has changed
            curr = nxt;
        }
        // Reseting
        prev = NULL;
        nxt = NULL;
    }
}

void suppression_titre(BiblioH* b, char* titre) {
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            nxt = curr->suiv;
            if (strcmp(curr->titre, titre) == 0) {
                if (prev) prev->suiv = nxt;
                else b->T[i] = nxt;
                liberer_livre(curr);
            } else prev = curr; // No element removed, previous has changed
            curr = nxt;
        }
        // Reseting
        prev = NULL;
        nxt = NULL;
    }
}

void suppression_auteur(BiblioH* b, char* auteur) {
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    curr = b->T[index];
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->titre, auteur) == 0) {
            if (prev) prev->suiv = nxt;
            else b->T[index] = nxt;
            liberer_livre(curr);
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}
