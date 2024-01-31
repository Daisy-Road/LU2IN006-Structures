#include "poste.h"

#include <stdio.h>
#include <stdlib.h>

Poste* creerBureauPoste(int size) {
    Poste* res = (Poste*)malloc(sizeof(Poste));
    res->size = size;
    res->tab = (ListDC*) malloc(size*sizeof(ListDC));
    for(int i = 0; i<size; i++) initialiserListe(res->tab+i); 
    return res;
}
