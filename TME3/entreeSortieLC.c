#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 256

Biblio* charger_n_entrees(char* nom_fic, int n) {
    Biblio* res = creer_biblio();
    FILE* f = fopen(nom_fic, "r");

    if (f == NULL) { printf("File %s is not readable\n", nom_fic); }

    char titre[MAX_BUFF_SIZE];
    char auteur[MAX_BUFF_SIZE];
    int num;

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %s %s\n", &num, titre, auteur);
        inserer_en_tete(res, num, titre, auteur);
    }
    fclose(f);
    return res;
}

void enregistrer_biblio(Biblio* b, char* nom_fic) {
    FILE* f = fopen(nom_fic, "w");

    Livre* curr = b->L;

    while (curr) {
        fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }

    fclose(f);
}

void afficher_livre(Livre* l) {
    if (l == NULL) {
        printf("Ce livre n'existe pas.\n");
        return;
    }
    printf("Livre %d: \"%s\" de %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio* b) {
    if(!b)return;
    printf("-----[ Bibliothèque ]-----\n");
    Livre* curr = b->L;
    while (curr) {
        afficher_livre(curr);
        curr = curr->suiv;
    }
    printf("--------------------------\n");
}

Livre* recherche_num(Biblio* b, int num) {
    if(!b)return NULL;
    Livre* curr = b->L;
    while (curr) {
        if (curr->num == num) return curr;
        curr = curr->suiv;
    }
    return NULL;
}

Livre* recherche_titre(Biblio* b, char* titre) {
    if(!b)return NULL;
    Livre* curr = b->L;
    while (curr) {
        if (strcmp(curr->titre, titre) == 0) return curr;
        curr = curr->suiv;
    }
    return NULL;
}

Biblio* recherche_auteur(Biblio* b, char* auteur) {
    if(!b)return NULL;
    Biblio* res = creer_biblio();
    Livre* curr = b->L;

    while (curr) {
        if (strcmp(curr->auteur, auteur) == 0)
            inserer_en_tete(res, curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }
    return res;
}

void suppression_num(Biblio* b, int num) {
    if(!b)return;
    Livre* curr = b->L;
    Livre* nxt = NULL;
    Livre* prev = NULL;
    while (curr) {
        nxt = curr->suiv;
        if (curr->num == num) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void suppression_titre(Biblio* b, char* titre) {
    if(!b)return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->titre, titre) == 0) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void suppression_auteur(Biblio* b, char* auteur) {
    if(!b)return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void suppression_livre(Biblio* b, int num, char* titre, char* auteur) {
    if(!b)return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    while (curr) {
        if ((curr->num == num) && (strcmp(curr->auteur, auteur) == 0) &&
            (strcmp(curr->titre, titre) == 0)) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // No element removed, previous has changed
        curr = nxt;
    }
}

void fusion_biblio(Biblio* b1, Biblio* b2) {
    if(!b1 || !b2)return;
    if (!b2) return;
    Livre* curr = b1->L;
    if (!curr) {
        b1->L = b2->L;
        free(b2);
    } else {
        while (curr->suiv) {
            curr = curr->suiv;
        }
        curr->suiv = b2->L;
        free(b2);
    }
}

Biblio* recherche_doublons(Biblio* b) { /* Doublons dans la liste finale. Peut
                                           êtrte optimisé avec un break */
    if(!b)return NULL;
    Livre* curr = b->L;
    Livre* curr2;
    Biblio* res = creer_biblio();
    int bool;
    while (curr) {
        bool = 1;
        curr2 = b->L;
        while (curr2 && bool) {
            if ((strcmp(curr->titre, curr2->titre) == 0) &&
                (strcmp(curr->auteur, curr2->auteur) == 0)&&(curr!=curr2)) {
                inserer_en_tete(res, curr->num, curr->titre, curr->auteur);
                bool = 0;
            }
            curr2 = curr2->suiv;
        }
        curr = curr->suiv;
    }
    return res;
}
