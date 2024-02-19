#include "biblioH.h"
#include "biblioLC.h"

#include "entreeSortieH.h"
#include "entreeSortieLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_RECHERCHES 100

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Paramètres invalides: %s <taille de la hash table>", argv[0]);
        return 1;
    }

    printf("Nos recherches seront faites sur GdeBiblio.txt avec l'intégralité "
           "de ses entrées.\n");
    Biblio* b = charger_n_entrees("GdeBiblio.txt", 100000);
    BiblioH* bH = charger_n_entreesH("GdeBiblio.txt", 100000, atoi(argv[1]));
    clock_t start;
    clock_t end;
    double cpu_time_use;

    // ------ Recherche par num -------
    printf("----- [ Recherche num ] ------\n");
    // Existant
    printf("1. Le numéro est existant\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_num(b, 76653);
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_numH(bH, 76653);
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);
    // Non Existant
    printf("\n2. Le numéro n'existe pas\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_num(b, 100000);
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_numH(bH, 100000);
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);

    // ------ Recherche par titre -------
    printf("\n----- [ Recherche titre ] ------\n");
    // Existant
    printf("1. Le titre est existant\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_titre(b, "BUCZYOJVIUBUZDRXJU");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_titreH(bH, "BUCZYOJVIUBUZDRXJU");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);

    // Non-Existant
    printf("\n2. Le titre n'existe pas\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_titre(b, "a");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_titreH(bH, "a");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);

    // ------ Recherche par auteur -------
    printf("\n----- [ Recherche auteur ] ------\n");
    // Existant
    printf("1. L'auteur est existant\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_auteur(b, "jgkln");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_auteurH(bH, "jgklnJ");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);

    // Non-Existant
    printf("\n2. L'auteur n'existe pas\n");
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_auteur(b, "a");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Liste chaînée: %f\n", cpu_time_use);
    start = clock();
    for (int i = 0; i < NB_RECHERCHES; i++)
        recherche_auteurH(bH, "a");
    end = clock();
    cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hashtable: %f\n", cpu_time_use);

    liberer_biblio(b);
    liberer_biblioH(bH);
}
