#ifndef POSTE_H
#define POSTE_H

#include "ldc.h"

typedef struct _Poste {
    int size;
    ListDC* tab;
} Poste;

Poste* creerBureauPoste(int size);


#endif
