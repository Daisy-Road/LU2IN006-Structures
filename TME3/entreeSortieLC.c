#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 256

Biblio* charger_n_entrees(char* nom_fic, int n) {
    Biblio* res = creer_biblio();
    FILE* f = fopen(nom_fic, "r");

    char titre[MAX_BUFF_SIZE];
    char auteur[MAX_BUFF_SIZE];
    int num;
    
    for(int i=0; i<n; i++) {
        fscanf(f, "%d %s %s\n", &num, titre, auteur);
        inserer_en_tete(res, num, titre, auteur); 
    }
    fclose(f);
    return res;
}

void enregistrer_biblio(Biblio* b, char* nom_fic) {
    FILE* f = fopen(nom_fic, "w");
    
    Livre* curr = b->L;
    
    while(curr) {
        fprintf(f, "%d %s %s\n", curr->num, curr->titre, curr->auteur);
        curr = curr->suiv;
    }

    fclose(f);
}

void afficher_livre(Livre* l) {
    printf("Livre %d: \"%s\" de %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio* b) {
    printf("-----[ Bibliothèque ]-----");
    Livre* curr = b->L;
    while(curr) {
        afficher_livre(curr);
        curr = curr->suiv;
    }
    printf("--------------------------");
}

Livre* recherche_num(Biblio* b, int num) {
    Livre* curr = b->L;
    while(curr) {
        if(curr->num == num) return curr;
        curr=curr->suiv;
    }
    return NULL;
}

Livre* recherche_titre(Biblio* b, char* titre) {
    Livre* curr = b->L;
    while(curr) {
        if(strcmp(curr->titre, titre) == 0) return curr;
        curr=curr->suiv;
    }
    return NULL;
}

Biblio* recherche_auteur(Biblio* b, char* auteur) {
    Biblio* res = creer_biblio();
    Livre* curr = b->L;
    
    while(curr) {
        if(strcmp(curr->auteur, auteur) == 0) inserer_en_tete(res, curr->num, curr->titre, curr->auteur);
        curr=curr->suiv;
    }
    return res;
}

void suppression_num(Biblio* b, int num) {
    Livre* curr = b->L;
    Livre* prev = NULL;
    while(curr) {
        if(curr->num == num) {
           if(prev) prev->suiv = curr->suiv;
           else b->L = curr->suiv;
           liberer_livre(curr);
        }
        prev = curr;
        curr = curr->suiv;
    }
}

void suppression_titre(Biblio* b, char* titre) {
    Livre* curr = b->L;
    Livre* prev = NULL;
    while(curr) {
        if(strcmp(curr->titre,titre)==0) {
           if(prev) prev->suiv = curr->suiv;
           else b->L = curr->suiv;
           liberer_livre(curr);
        }
        prev = curr;
        curr = curr->suiv;
    }
}

void suppression_auteur(Biblio* b, char* auteur) {
    Livre* curr = b->L;
    Livre* prev = NULL;
    while(curr) {
        if(strcmp(curr->auteur,auteur)==0) {
           if(prev) prev->suiv = curr->suiv;
           else b->L = curr->suiv;
           liberer_livre(curr);
        }
        prev = curr;
        curr = curr->suiv;
    }
}

void fusion_biblio(Biblio* b1, Biblio* b2){
    Livre* curr= b1->L;
    if(!curr){
        b1->L=b2->L;
        free(b2);
    }
    else{
        while(curr->suiv){
            curr=curr->suiv;
        }
        curr->suiv=b2->L;
        free(b2);
    }

}

Livre* recherche_livres(Biblio* b){
    Livre* curr= b->L;
    Livre* curr2;
    Biblio* res= creer_biblio();
    int bool=1
    while (curr){
        
            curr2=b1->L;
            while(curr2){
                if (strcmp(curr->titre,curr2->titre)==0 && strcmp(curr->auteur,curr2->auteur)==0&&curr->num!=curr2->num){
                    inserer_en_tete(res,curr->num,titre,auteur);
       

            }
                    
    }

}


