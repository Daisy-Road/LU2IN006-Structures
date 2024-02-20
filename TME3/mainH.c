#include "biblioH.h"
#include "entreeSortieH.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void menu() {
    printf("\n0-%s\n1-%s\n2-%s\n3-%s\n4-%s\n5-%s\n6-%s\n7-%s\n8-%s\n9-%s\n",
           "Sortir du programme", "Ajouter ouvrage", "Supprimer ouvrage",
           "Afficher bibliothèque", "Rechercher ouvrage par numéro",
           "Rechercher ouvrage pas titre", "Rechercher les livres d'un auteur",
           "Fusionner cette bibliothèque avec une autre",
           "Rechercher tous les ouvrages avec plusieurs exemplaires",
           "Sauvegarder la bibliothèque\n");
}

void menu_suppression() {
    printf("1- Supression par numéro\n"
           "2- Suppression par titre\n"
           "3- Suppression par auteur\n"
           "4- Suppression par numéro, auteur et titre\n"
           "\nTout autres entrées vous fera sortir de ce mode.\n");
}

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Paramètres invalides: %s <fichier> <nombre d'entrees a "
               "charger> [hash table size]\n",
               argv[0]);
        return 1;
    }

    // On vérifie si la taille de la table de hachage a été donné en paramètre
    // Sinon on prends la valeur par défaut (le nombre de livre chargé / 2)
    int sizeHash = (argc == 4) ? atoi(argv[3]) : atoi(argv[2]) / 2;

    BiblioH* b = charger_n_entreesH(argv[1], atoi(argv[2]), sizeHash);

    char entree[3]; // Une entrée ne devrait pas dépasser un chiffre
                    // (entree[1] est le \n, entree[2] est le \0)
    do {
        menu();
        fgets(entree, 3, stdin);
        char num[MAX_BUFFER_SIZE];
        char titre[MAX_BUFFER_SIZE];
        char nom[MAX_BUFFER_SIZE];
        char auteur[MAX_BUFFER_SIZE];
        char nb[MAX_BUFFER_SIZE];
        switch (atoi(entree)) {

        case 1:
            printf("Veuillez indiquer le numéro de l'ouvrage\n");
            fgets(num, MAX_BUFFER_SIZE, stdin);
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, 256, stdin);
            titre[strcspn(titre, "\n")] = 0;
            printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;
            insererH(b, atoi(num), titre, nom);
            printf("Livre ajouté\n");
            break;

        case 2:
            menu_suppression();
            fgets(entree, 3, stdin);
            switch (atoi(entree)) {
            case 1:
                printf("Veuillez écrire le numéro des ouvrages.\n");
                fgets(num, 256, stdin);
                suppression_numH(b, atoi(num));
                entree[0] = '0';
                printf("Livres supprimées\n");
                break;
            case 2:
                printf("Veuillez écrire le titre des ouvrages.\n");
                fgets(titre, 256, stdin);
                titre[strcspn(titre, "\n")] = 0;
                suppression_titreH(b, titre);
                entree[0] = '0';
                printf("Livres supprimées\n");
                break;
            case 3:
                printf("Veuillez écrire l'auteur des ouvrages.\n");
                fgets(auteur, 256, stdin);
                auteur[strcspn(auteur, "\n")] = 0;
                suppression_auteurH(b, auteur);
                entree[0] = '0';
                printf("Livres supprimées\n");
                break;
            case 4:
                printf("Veuillez écrire le numéro de l'ouvrage.\n");
                fgets(num, 256, stdin);
                printf("Veuillez écrire le titre de l'ouvrage.\n");
                fgets(titre, 256, stdin);
                titre[strcspn(titre, "\n")] = 0;
                printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
                fgets(nom, 256, stdin);
                nom[strcspn(nom, "\n")] = 0;
                suppression_ouvrageH(b, atoi(num), titre, nom);
                printf("Ouvrage");
                break;
            default:
                break;
            }
            entree[0] = '2'; // Remise à zéro de l'entrée
            break;

        case 3:
            afficher_biblioH(b);
            break;

        case 4:
            printf("Veuillez écrire le numero de l'ouvrage.\n");
            fgets(num, 256, stdin);
            afficher_livreH(recherche_numH(b, atoi(num)));
            break;

        case 5:
            printf("Veuillez écrire le titre de l'ouvrage.\n");
            fgets(titre, 256, stdin);
            titre[strcspn(titre, "\n")] = 0;
            afficher_livreH(recherche_titreH(b, titre));
            break;

        case 6:
            printf("Veuillez écrire le nom de l'auteur de l'ouvrage.\n");
            fgets(auteur, 256, stdin);
            auteur[strcspn(auteur, "\n")] = 0;
            printf("Affichage des livres de %s.\n", auteur);
            BiblioH* sameAuthor = recherche_auteurH(b, auteur);
            afficher_biblioH(sameAuthor);
            liberer_biblioH(sameAuthor);
            break;

        case 7:
            printf("Veuillez écrire le nom du fichier.\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;
            printf("Veuillez écrire le nombre de livres du fichier.\n");
            fgets(nb, 256, stdin);
            printf(
                "Veuillez indiquer la taille de la table de hachage à générer\n"
                "Taille actuelle: %d\n"
                "Prendre une valeur différente que la taille actuel "
                "recalculera le hachage de la nouvelle bibliothèque générée\n",
                sizeHash);
            fgets(num, 256, stdin);
            sizeHash = atoi(num);
            BiblioH* b2 = charger_n_entreesH(nom, atoi(nb), sizeHash);
            fusionH(b, b2);
            printf("Fusion effectuée.\n");
            break;

        case 8:
            printf("Affichage des doublons...\n");
            BiblioH* dub = recherche_doublonsH(b);
            afficher_biblioH(dub);
            liberer_biblioH(dub);
            break;

        case 9:
            printf("Sous quel nom sauvegarder la bibliothèque courante ?\n");
            fgets(nom, 256, stdin);
            nom[strcspn(nom, "\n")] = 0;
            enregistrer_biblioH(b, nom);
            printf("Bibliothèque sauvegardée sous %s\n", nom);

        case 0:
            break;

        default:
            printf("Commande non valide\n");
        }

    } while (atoi(entree) != 0);

    printf("Merci et bonne journée!\n");
    liberer_biblioH(b);
    return 0;
}
