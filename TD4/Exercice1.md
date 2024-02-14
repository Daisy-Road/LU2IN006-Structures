# Exercice 1

## Q.1.1
On donne les structures suivantes:
```c
typedef struct Form Formation;

typedef struct element {
    Formation* f;
    struct element* suiv;
} Element;

struct Form {
    char* nom;
    int nbHeures;
    Element* L_form;
};
```

## Q.1.2

On définit le catalogue comme suit:
```c
typedef struct {
    int M;
    int n;
    Formation** T;
} Catalogue;
```

## Q.1.3

To import

## Q.1.4

```c
void affichage_formation(Formation* F) {
    if(F->nbHeures == 0) {
        printf("Formation %s: " F->nom);
        Element* curr = F->L_form;
        while(curr) {
            printf("%s " curr->f->nom);
            curr = curr->suiv;
        }
        printf("\n");
    } else {
        printf("Cours %s\n", F->nom);
    }
}
```

```c
void affichage_catalogue(Catalogue* C) {
    for(int i=0; i<C->n; i++) {
        affichage_formation(C->T[i]);
    }
}
```

## Q.1.5

```c
int nombre_heure_total(Formation* F) {
    int res = F->nbHeures;
    Element* curr = F->L_form;
    while(curr) {
        res += nombre_heure_total(curr->F);
        curr = curr->suiv;
    }
    return res;
}
```

## Q.1.6

L'affichage est le suivant:
```
Formation F1: C1 F2
```
Le nombre d'heure renverra `30`:
```
0+12+8+10 = 30
```

## Q.1.7

L'affichage sera inchangé:
```
Formation F1: C1 F2
```
Par contre l'appel récursif pour le nombre d'heure ne s'arrête jamais.  

La même situation se produit dans l'autre cas

## Q.1.8

Pour éviter les cycles, il faut rechercher de manière récursive si la référence n'existe pas déjà.
