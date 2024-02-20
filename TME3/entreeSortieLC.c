#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 256

Biblio* charger_n_entrees(char* nom_fic, int n) {
    /* Charge "n" entrées de livres dans le fichier
     * "nom_fic" dans une liste chaînée qui sera renvoyée */
    Biblio* res = creer_biblio();
    FILE* f = fopen(nom_fic, "r");

    if (f == NULL) {
        printf("File %s is not readable\n", nom_fic);
        return NULL;
    }

    char titre[MAX_BUFF_SIZE];
    char auteur[MAX_BUFF_SIZE];
    int num;

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d %s %s\n", &num, titre, auteur) == EOF) break;
        inserer_en_tete(res, num, titre, auteur);
    }
    fclose(f);
    return res;
}

void enregistrer_biblio(Biblio* b, char* nom_fic) {
    /* Enregistre la bibliothèque "b" dans le fichier "nom_fic" */
    FILE* f = fopen(nom_fic, "w");

    Livre* curr = b->L;

    while (curr) {
        fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }

    fclose(f);
}

void afficher_livre(Livre* l) {
    /* Affiche le livre "l" avec son numéor, son titre et son auteur */
    if (l == NULL) {
        printf("Ce livre n'existe pas.\n");
        return;
    }
    printf("Livre %d: \"%s\" de %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio* b) {
    /* Affiche tous les livres de la bibliothèque "b" avec
     * leur numéro, leur titre, et leur auteur */
    if (!b) return;
    printf("-----[ Bibliothèque ]-----\n");
    Livre* curr = b->L;
    while (curr) {
        afficher_livre(curr);
        curr = curr->suiv;
    }
    printf("--------------------------\n");
}

Livre* recherche_num(Biblio* b, int num) {
    /* Renvoie le premier livre de "b" portant le numéro "num" */
    if (!b) return NULL;
    Livre* curr = b->L;
    while (curr) {
        if (curr->num == num) return curr;
        curr = curr->suiv;
    }
    return NULL;
}

Livre* recherche_titre(Biblio* b, char* titre) {
    /* Renvoie le premier livre de "b" portant le titre "titre" */
    if (!b) return NULL;
    Livre* curr = b->L;
    while (curr) {
        if (strcmp(curr->titre, titre) == 0) return curr;
        curr = curr->suiv;
    }
    return NULL;
}

Biblio* recherche_auteur(Biblio* b, char* auteur) {
    /* Renvoie une bibliothèque de livre de "b" écrit par l'auteur "auteur" */
    if (!b) return NULL;
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
    /* Supprime le ou les livres de "b" portant le numéro "num" */
    if (!b) return;
    Livre* curr = b->L;
    Livre* nxt = NULL;
    Livre* prev = NULL;
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        nxt = curr->suiv;
        if (curr->num == num) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("------\n");
}

void suppression_titre(Biblio* b, char* titre) {
    /* Supprime le ou les livres de "b" titré "titre" */
    if (!b) return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->titre, titre) == 0) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("------\n");
}

void suppression_auteur(Biblio* b, char* auteur) {
    /* Supprime le ou les livres de "b" de l'auteur "auteur" */
    if (!b) return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("-----\n");
}

void suppression_livre(Biblio* b, int num, char* titre, char* auteur) {
    /* Supprime le ou les livres de "b" portant le numéro "num", titré "titre"
     * et écrit par "auteur" */
    if (!b) return;
    Livre* curr = b->L;
    Livre* prev = NULL;
    Livre* nxt = NULL;
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        if ((curr->num == num) && (strcmp(curr->auteur, auteur) == 0) &&
            (strcmp(curr->titre, titre) == 0)) {
            if (prev) prev->suiv = nxt;
            else b->L = nxt;
            afficher_livre(curr);
            liberer_livre(curr);
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("-----\n");
}

void fusion_biblio(Biblio* b1, Biblio* b2) {
    /* Fusionne tout le contenu de la bibliothèque "b2"
     * dans la bibliothèque "b1" et libère b2 */
    if (!b1 || !b2) return;
    Livre* curr = b1->L;
    if (!curr) {
        b1->L = b2->L;
        free(b2); // On free ici, car on ne veut pas supprimer les livres
    } else {
        while (curr->suiv) {
            curr = curr->suiv;
        }
        curr->suiv = b2->L;
        free(b2); // Idem
    }
}

Biblio* recherche_doublons(Biblio* b) {
    /* Renvoie une bibliothèque contenant l'ensemble des doublons de "b"
     *Un doublon est indetifiable par le même titre
     * et le même auteur, mais le numéro peut être différent
     * Ces livres doublons sont dupliquées dans la bibliothèque renvoyée */
    if (!b) return NULL;
    Livre* curr = b->L;
    Livre* curr2;
    Biblio* res = creer_biblio();
    while (curr) {
        curr2 = curr->suiv;
        while (curr2) {
            if ((strcmp(curr->titre, curr2->titre) == 0) &&
                (strcmp(curr->auteur, curr2->auteur) == 0) && (curr != curr2)) {
                inserer_en_tete(res, curr->num, curr->titre, curr->auteur);
                break;
            }
            curr2 = curr2->suiv;
        }
        curr = curr->suiv;
    }
    return res;
}
