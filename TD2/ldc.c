#include <stdlib.h>
#include <stdio.h>
#include "ldc.h"

ListDCEl* creerElement(int value) {
    ListDCEl* el = (ListDCEl*) malloc(sizeof(ListDCEl));
    el->val = value;
    el->prev = NULL;
    el->next = NULL;
    return el;
}

void initialiserListe(ListDC* l) {
    l->head = NULL;
    l->tails = NULL;
}

ListDC* creerListe() {
    ListDC* res = malloc(sizeof(ListDC));
    initialiserListe(res);
    return res;
}

int listeVide(ListDC* l) {
    return l->head == NULL;
}

void insererEnTete(ListDC* l, int value) {
    ListDCEl* new = creerElement(value); 
    new->next = l->head;
    if(!listeVide(l)) l->head->prev = new;
    l->head = new;
    if(l->tails == NULL) l->tails=new;
}

void insererEnFin(ListDC* l, int value) {
    ListDCEl* new = creerElement(value);
    new->prev = l->tails;
    if(!listeVide(l)) l->tails->next = new;
    l->tails = new;
    if(l->head == NULL) l->head=new;
}

void afficher(ListDC* l) {
    printf("Liste à l'envers:\n");
    ListDCEl* curr = l->tails;
    while(curr) {
        printf("%d ", curr->val);
        curr = curr->prev;
    }
    printf("\n");
}

ListDCEl* rechercher(ListDC* l, int value) {
    ListDCEl* curr = l->head;
    while(curr && curr->val != value) curr = curr->next;
    return curr;
}

void supprimerElement(ListDC* l, ListDCEl* el) {
    
    if(!el->prev) l->head = el->next;
    else el->prev->next = el->next;
    
    if(!el->next) l->tails = el->prev;
    else el->next->prev = el->prev;

    free(el);

}

int supprimerTete(ListDC* l) {
    if(listeVide(l)) return 0;
    int val = l->head->val;
    supprimerElement(l, l->head);
    return val;
}

int supprimerFin(ListDC* l) {
    if(listeVide(l)) return 0;
    int val = l->tails->val;
    supprimerElement(l, l->tails);
    return val;
}

void desalloueListe(ListDC* l) {
    ListDCEl* curr = l->head;
    while(curr->next) {
        curr =curr->next;
        free(curr->prev);
    }
    free(curr);
    free(l);
}
