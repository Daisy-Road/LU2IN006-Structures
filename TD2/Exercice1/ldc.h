#ifndef LDC_H
#define LDC_H

typedef struct _ListDCEl {
    int val;
    struct _ListDCEl* prev;
    struct _ListDCEl* next;
} ListDCEl;

typedef struct _ListDC {
    ListDCEl* head;
    ListDCEl* tails;
} ListDC;

ListDCEl* creerElement(int value);

void initialiserListe(ListDC* l);
ListDC* creerListe();
int listeVide(ListDC* l);

void insererEnTete(ListDC* l, int value);

#endif
