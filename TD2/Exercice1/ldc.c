#include <stdlib.h>
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
