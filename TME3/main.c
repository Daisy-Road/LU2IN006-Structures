#include "biblioLC.h"
#include "entreeSortieLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void menu() {
    printf("\n0-%s\n1-%s\n2-%s\n3-%s\n4-%s\n5-%s\n6-%s\n7-%s\n8-%s\n",
           "Sortir du programme", "Ajouter ouvrage", "Supprimer ouvrage",
           "Afficher bibliothèque", "Rechercher ouvrage par numéro",
           "Rechercher ouvrage pas titre", "Rechercher les livres d'un auteur",
           "Fusionner cette bibliothèque avec une autre",
           "Rechercher tout les ouvrages avec plusieurs exemplaires\n");
}

int main(int argc, char** argv) {

    Biblio* b = charger_n_entrees(argv[1], atoi(argv[2]));

    char entree[MAX_BUFFER_SIZE];
    do {
        menu();
        fgets(entree, MAX_BUFFER_SIZE, stdin);
        char num[MAX_BUFFER_SIZE];
        char titre[MAX_BUFFER_SIZE];
        char nom[MAX_BUFFER_SIZE];
        char auteur[MAX_BUFFER_SIZE];
        char nb[MAX_BUFFER_SIZE];
        switch (atoi(entree)) {

        case 1:
            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            fgets(titre, 256, stdin);
            titre[strcspn(titre, "\n")] = 0;
            printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;
            if (atoi(num) != 0) {
                inserer_en_tete(b, atoi(num), titre, nom);
                printf("Livre ajouté\n");
            } else {
                printf("Erreur format\n");
            }
            break;

        case 2:
            printf("Veuillez écrire le numéro de l'ouvrage.\n");
            fgets(num, 256, stdin);
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, 256, stdin);
            titre[strcspn(titre, "\n")] = 0;
            printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;

            if (atoi(num) != 0) {
                suppression_livre(b, atoi(num), titre, nom);
                printf("Livre supprimé\n");
            } else {
                printf("Erreur format\n");
            }
            break;

        case 3:
            afficher_biblio(b);
            break;

        case 4:
            printf("Veuillez écrire le numero de l'ouvrage.\n");
            fgets(num, 256, stdin);
            if (atoi(num) != 0) {
                afficher_livre(recherche_num(b, atoi(num)));
            } else {
                printf("Erreur format\n");
            }
            break;

        case 5:
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, 256, stdin);
            afficher_livre(recherche_titre(b, titre));
            break;

        case 6:
            printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
            fgets(auteur, 256, stdin);
            Biblio* sameAuthor = recherche_auteur(b, auteur);
            afficher_biblio(sameAuthor);
            free(sameAuthor);
            break;

        case 7:
            printf("Veuillez écrire le nom du fichier.\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;
            printf("Veuillez écrire le nombre de livres du fichier.\n");
            fgets(nb, 256, stdin);
            Biblio* b2 = charger_n_entrees(nom, atoi(nb));
            fusion_biblio(b, b2);
            printf("Fusion effectuée.\n");
            break;

        case 8:
            printf("Affichage des ouvrages en double\n");
            Biblio* doublons = recherche_doublons(b);
            afficher_biblio(doublons);
            free(doublons);
            break;

        case 0:
            break;

        default:
            printf("Commande non valide\n");
        }

    } while (atoi(entree) != 0);

    printf("Merci et bonne journée!\n");
    liberer_biblio(b);
    return 0;
}
