#include "biblioH.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fonctionClef(char* auteur) {
    /* Renvoie la clé liées à un auteur
     * Il s'agit juste de la somme des caractères ASCII */
    int res = 0;
    for (int i = 0; auteur[i]; i++) {
        res += (int)auteur[i];
    }
    return res;
}

LivreH* creer_livreH(int num, char* titre, char* auteur) {
    /* Alloue la mémoire nécéssaire pour un livre de numéro "num",
     * de titre "titre" et d'auteur "auteur" */
    LivreH* res = (LivreH*)malloc(sizeof(LivreH));
    res->clef = fonctionClef(auteur);
    res->auteur = strdup(auteur);
    res->titre = strdup(titre);
    res->num = num;
    return res;
}

void liberer_livreH(LivreH* l) {
    /* Libère l'intégralité du bloc mémoire "l" */
    free(l->auteur);
    free(l->titre);
    free(l);
}

BiblioH* creer_biblioH(int m) {
    /* Créer une table de hachage de taille m et
     * l'intitialisé à NULL
     * m doit être strictement positif */
    if (m <= 0) {
        printf("Taille de la table de hachage invalide\n");
        return NULL;
    }
    BiblioH* res = (BiblioH*)malloc(sizeof(BiblioH));
    res->nE = 0;
    res->m = m;
    res->T = (LivreH**)malloc(m * sizeof(LivreH*));
    for (int i = 0; i < m; i++) {
        res->T[i] = NULL;
    }
    return res;
}

void liberer_biblioH(BiblioH* b) {
    /* Libère l'entiereté du contenu de la table de hachage:
     * L'ensemble des livres qui y sont stockés et le bloc mémoire "b" */
    if (!b) return;
    LivreH* curr;
    LivreH* tmp;
    for (int i = 0; i < b->m; i++) {
        curr = b->T[i];
        while (curr) {
            tmp = curr->suiv;
            liberer_livreH(curr);
            curr = tmp;
        }
    }
    free(b->T);
    free(b);
}

int fonctionHachage(int cle, int m) {
    /* Calcule le hash de la "cle" pour une table de hachage
     * de taille "m". */
    float A = (sqrt(5) - 1) / 2;
    return (int)(m * (cle * A - (int)(cle * A)));
}

void insererH(BiblioH* b, int num, char* titre, char* auteur) {
    /* Alloue l'espace nécéssaire pour ajouter un livre
     * de numéro "num", de titre "titre" et d'auteur "auteur"
     * et l'ajoute à la table de hachage b */
    LivreH* new = creer_livreH(num, titre, auteur);
    int hash = fonctionHachage(new->clef, b->m);
    new->suiv = b->T[hash];
    b->T[hash] = new;
    b->nE++;
}
