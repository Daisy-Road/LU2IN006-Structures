#include "entreeSortieH.h"
#include "biblioH.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

BiblioH* charger_n_entreesH(char* nom_fic, int n, int size) {
    FILE* f = fopen(nom_fic, "r");
    if (!f) {
        printf("Nom de fichier invalide\n");
        return NULL;
    }
    BiblioH* b = creer_biblioH(size);
    int num;
    char auteur[MAX_BUFFER_SIZE];
    char titre[MAX_BUFFER_SIZE];
    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %s %s\n", &num, titre, auteur) == EOF) break;
        insererH(b, num, titre, auteur);
    }
    fclose(f);
    return b;
}

void enregistrer_biblioH(BiblioH* b, char* nom_fic) {
    FILE* f = fopen(nom_fic, "w");
    if (!f) return;
    if (b) {
        LivreH* curr;
        for (int i = 0; i < b->m; i++) {
            curr = b->T[i];
            while (curr) {
                fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
                curr = curr->suiv;
            }
        }
    }
    fclose(f);
}

void afficher_livreH(LivreH* l) {
    if (!l) printf("Ce livre n'existe pas.\n");
    else {
        printf("Livre %d (%d): \"%s\" de %s\n", l->num, l->clef, l->titre,
               l->auteur);
    }
}

void afficher_biblioH(BiblioH* b) {
    if (!b) {
        printf("Cette bibliothèque n'existe pas\n");
    } else {
        printf("------ [ Bibliotheque ] ------\n");
        LivreH* curr;
        for (int i = 0; i < b->m; i++) {
            curr = b->T[i];
            while (curr) {
                afficher_livreH(curr);
                curr = curr->suiv;
            }
        }
        printf("------------------------------\n");
    }
}

LivreH* recherche_numH(BiblioH* b, int num) {
    if (b) {
        LivreH* curr;
        for (int i = 0; i < b->m; i++) {
            curr = b->T[i];
            while (curr) {
                if (curr->num == num) return curr;
                curr = curr->suiv;
            }
        }
    }
    return NULL;
}

LivreH* recherche_titreH(BiblioH* b, char* titre) {
    if (b) {
        LivreH* curr;
        for (int i = 0; i < b->m; i++) {
            curr = b->T[i];
            while (curr) {
                if (strcmp(curr->titre, titre) == 0) return curr;
                curr = curr->suiv;
            }
        }
    }
    return NULL;
}

BiblioH* recherche_auteurH(BiblioH* b, char* auteur) {
    if (!b) return NULL;
    BiblioH* res = creer_biblioH(1);
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    LivreH* curr = b->T[index];
    while (curr) {
        if (strcmp(curr->auteur, auteur) == 0)
            insererH(res, curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }
    return res;
}

void suppression_numH(BiblioH* b, int num) {
    if (!b) return;
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
                afficher_livreH(curr);
                liberer_livreH(curr);
                b->nE--;
            } else prev = curr; // No element removed, previous has changed
            curr = nxt;
        }
        // Reseting
        prev = NULL;
        nxt = NULL;
    }
}

void suppression_titreH(BiblioH* b, char* titre) {
    if (!b) return;
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
                afficher_livreH(curr);
                liberer_livreH(curr);
                b->nE--;
            } else prev = curr; // No element removed, previous has changed
            curr = nxt;
        }
        // Reseting
        prev = NULL;
        nxt = NULL;
    }
}

void suppression_auteurH(BiblioH* b, char* auteur) {
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    curr = b->T[index];
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0) {
            if (prev) prev->suiv = nxt;
            else b->T[index] = nxt;
            afficher_livreH(curr);
            liberer_livreH(curr);
            b->nE--;
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void suppression_ouvrageH(BiblioH* b, int num, char* titre, char* auteur) {
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    curr = b->T[index];
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0 &&
            strcmp(curr->titre, titre) == 0 && curr->num == num) {
            if (prev) prev->suiv = nxt;
            else b->T[index] = nxt;
            afficher_livreH(curr);
            liberer_livreH(curr);
            b->nE--;
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void fusionH(BiblioH* b1, BiblioH* b2) {
    if (!b1 || !b2) return;

    if (b1->m == b2->m) {
        // Keys are going to be the same, no need to recaculate
        LivreH* curr;
        for (int i = 0; i < b1->m; i++) {
            curr = b1->T[i];
            if (!curr) b1->T[i] = b2->T[i];
            else {
                while (curr->suiv)
                    curr = curr->suiv;

                curr->suiv = b2->T[i];
            }
        }
        b1->nE += b2->nE;
        free(b2->T);
        free(b2);
        return;
    }
    // We need to recalculate the hash, because the size is different
    LivreH* curr;
    LivreH* tmp;
    int index;
    for (int i = 0; i < b2->m; i++) {
        curr = b2->T[i];
        while (curr) {
            index = fonctionHachage(curr->clef, b1->m);
            tmp = curr;
            curr = curr->suiv;
            tmp->suiv = b1->T[index];
            b1->T[index] = tmp;
        }
    }
    b1->nE += b2->nE;
    free(b2->T);
    free(b2);
}

void supprimer_doublonsH(BiblioH* b) {
    if (!b) return;
    LivreH* curr;
    LivreH* prev;
    LivreH* to_test;
    LivreH* tmp;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            to_test = curr->suiv;
            prev = curr;
            while (to_test) {
                if (strcmp(curr->titre, to_test->titre) == 0 &&
                    strcmp(curr->auteur, to_test->auteur) == 0) {
                    prev->suiv = to_test->suiv;
                    tmp = to_test->suiv;
                    liberer_livreH(to_test);
                    to_test = tmp;
                } else {
                    to_test = to_test->suiv;
                }
            }
            curr = curr->suiv;
        }
    }
}
