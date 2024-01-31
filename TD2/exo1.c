#include "ldc.h"
#define NULL (void*)0

int main(void) {
    ListDC* l = creerListe();
    insererEnTete(l, 12);
    insererEnFin(l, 7);
    afficher(l);
    
    ListDCEl* el = rechercher(l, 6);
    if(el != NULL) supprimerElement(l, el);

    desalloueListe(l);
    return 0;
}

