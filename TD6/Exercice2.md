# Exercice 2

## Q.1

On obtient un arbre dit dégénéré, aussi appelé arbre peigne (tous les éléments sont à droites).  
Equilibrer l'arbre permet d'avoir un temps de recherche de complexité logarithmique dans le pire cas 
au lieu d'une complexité linéaire, comme c'est parfois le cas pour des arbres dégénérés.  

## Q.2

Pour que ce soit efficace, on ajoute le champs "hauteur" dans un noeud. Celui-ci doit être initialisé à 0 lors de 
l'insertion d'une valeur dans l'arbre (feuille de l'arbre). Puis les hauteurs d'un noued sont mis à jour à chaque 
modification d'un de ses fils.  

```c
typedef struct noeud {
    int valeur,
    struct noeud* fg;
    struct noeud* fd;
    int hauteur;
} Noeud;
typedef Noeud* ABR;
```

## Q.3

```c
int hauteur(ABR ab) {
    if(!ab) return -1;
    return ab->hauteur;
}

void majhauteur(ABR ab) {
    if(!ab) return;
    ab->hauteur = 1 + (hauteur(ab->fg) > hauteur(ab->fd)) ? hauteur(ab->fg) : hauteur(ab->fd);
}
```

## Q.4

Comme la racine change, on donne en paramètre un pointeur sur ABR.

```c
void rotationDroite(ABR* ab) {
    Noeud* r = *ab;
    Noeud* g = (*ab)->fg;
    Noeud* v = g->fd;

    r->fg = v;
    g->fg = r;
    *ab = g;
    majhauteur((*ab)->fd);
    majhauteur(*ab);
}
```
