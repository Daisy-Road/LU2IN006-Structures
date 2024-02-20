#include "entreeSortieH.h"
#include "biblioH.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

BiblioH* charger_n_entreesH(char* nom_fic, int n, int size) {
    /* Charge "n" entrées de livres du fichier "nom_fic"
     * dans une table de hachage de taille "size"
     * qui sera renvoyée */
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
    /* Enregistre la table de hachage "b" dans le fichier
     * "nom_fic"
     * */
    FILE* f = fopen(nom_fic, "w");
    if (!f) {
        printf("Impossible d'écrire dans le fichier %s\n", nom_fic);
        return;
    }
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
    /* Affiche le livre l avec son numéro, sa clé, son titre et son auteur */
    if (!l) printf("Ce livre n'existe pas.\n");
    else {
        printf("Livre %d (%d): \"%s\" de %s\n", l->num, l->clef, l->titre,
               l->auteur);
    }
}

void afficher_biblioH(BiblioH* b) {
    /* Affiche tous les livres de la bibliothèque b
     * Avec leur numéro, leur clé, leur titre et leur auteur */
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
    /* Renvoie le premier livresdans la table de hachage b
     * qui porte le numéro "num" */
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
    /* Recherche le premier livre dans la table de hachage b
     * qui porte le titre "titre" */
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
    /* Renvoie une table de hachage de livres dans la table de hachage b
     * qui ont été écrit par "auteur" */
    if (!b) return NULL;
    BiblioH* res = creer_biblioH(1);
    // Inutile de créer une bibliothèque plus grande, la clé sera
    // la même pour tous les livres (donc le hachage aussi).
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
    /* Supprime tous les livres de b portant le numéro "num" */
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    printf("Les livres suivants seront supprimés...\n");
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
            } else prev = curr; // Pas d'élément supprimé, le précédent change
            curr = nxt;
        }
        // Remise à zéro
        prev = NULL;
        nxt = NULL;
    }
    printf("-----\n");
}

void suppression_titreH(BiblioH* b, char* titre) {
    /* Supprime tous les livres de b ayant pour titre "titre" */
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    printf("Les livres suivants seront supprimés...\n");
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
            } else prev = curr; // Pas d'élément supprimé, le précédent change
            curr = nxt;
        }
        // Remise à zéro
        prev = NULL;
        nxt = NULL;
    }
    printf("-----\n");
}

void suppression_auteurH(BiblioH* b, char* auteur) {
    /* Supprime tous les livres de b écrit par l'auteur "auteur" */
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    curr = b->T[index];
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0) {
            if (prev) prev->suiv = nxt;
            else b->T[index] = nxt;
            afficher_livreH(curr);
            liberer_livreH(curr);
            b->nE--;
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("-----\n");
}

void suppression_ouvrageH(BiblioH* b, int num, char* titre, char* auteur) {
    if (!b) return;
    LivreH* curr = NULL;
    LivreH* nxt = NULL;
    LivreH* prev = NULL;
    int index = fonctionHachage(fonctionClef(auteur), b->m);
    curr = b->T[index];
    printf("Les livres suivants seront supprimés...\n");
    while (curr) {
        nxt = curr->suiv;
        if (strcmp(curr->auteur, auteur) == 0 &&
            strcmp(curr->titre, titre) == 0 && curr->num == num) {
            if (prev) prev->suiv = nxt;
            else b->T[index] = nxt;
            afficher_livreH(curr);
            liberer_livreH(curr);
            b->nE--;
        } else prev = curr; // Pas d'élément supprimé, le précédent change
        curr = nxt;
    }
    printf("-----\n");
}

void fusionH(BiblioH* b1, BiblioH* b2) {
    /* Fusionne la table de hachage b2 avec b1 puis libère b2.
     * Si les tables ont des tailles différentes, on recalcule
     * la valeur de hachage des éléments de b2 pour satisfaire b1 */
    if (!b1 || !b2) return;

    if (b1->m == b2->m) {
        // Le hachage sera le même, pas besoin de recalculer
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
    // La taille de b1 est différente de b2, on recalcule le hachage
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

BiblioH* recherche_doublonsH(BiblioH* b) {
    /* Renvoie une bibliothèque contenant l'ensemble des doublons
     * stocké dans "b". Un doublon est indetifiable par le même titre
     * et le même auteur, mais le numéro peut être différent.
     * Les livres doublons sont dupliquée dans la bibliothèque renvoyée */
    if (!b) return NULL;
    LivreH* curr;
    LivreH* to_test;
    BiblioH* res = creer_biblioH(1);
    // Inutile de créer une bibliothèque plus grande, la clé sera
    // la même pour tous les livres (donc le hachage aussi).
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            to_test = curr->suiv;
            while (to_test) {
                if (strcmp(curr->titre, to_test->titre) == 0 &&
                    strcmp(curr->auteur, to_test->auteur) == 0 &&
                    curr != to_test) {
                    insererH(res, curr->num, curr->titre, curr->auteur);
                    // L'élément courant admet un doublon, donc il s'ajoute
                    // à la bibliothèque de retour. Et on passe au prochain
                    // élément
                    break;
                }
                to_test = to_test->suiv;
            }
            curr = curr->suiv;
        }
    }
    return res;
}
