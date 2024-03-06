# Exercice 1

## Q.1

```c
Noeud* rechercherValeur(ABR ab, int val) {
    if(!ab) return NULL;
    if(ab->valeur == val) return ab;
    if(ab->valeur < val) return rechercherValeur(ab->fd, val);
    return rechercherValeur(ab->fg, val);
}
```

## Q.2

```c
Noeud* creerNoeud(int valeur) {
    Noeud* res = (Noeud*) malloc(sizeof(Noeud));
    res->valeur = valeur;
    res->fd = NULL;
    res->fg = NULL;
    return res;
}

void insererElem(ABR* ab, int val) {
    if(!*ab) *ab = creerNoeud(valeur);
    else if((*ab)->val < val) insererElem(&((*ab)->fd), val);
    else insererElem(&((*ab)->fg), val);
}
```

## Q.3

Quand on supprime un noeud dans un ABR, il faut recoller l'arbre de sorte à garder la structure d'arbre binaire, et s'assurer 
que la propriété sur les clés est vérifiée.  
Pour y parvenir, considérons les cas suivants:

- Quand le noeud à supprimer ne possède qu'un seul fils, il suffit de le remplacer par celui-ci
- Quand le noeud $n$ a supprimer possède 2 fils, il faut le remplacer par le noeud $m$ de plus grande valeur dans 
son sous arbre gauche (ou celui de plus petite valeur dans le sous arbre droit)  

Dans un ABR, le noeud de plus grande valeur est celui qui est situé tout à droite. Pour trouver un tel noeud $m$ il suffit 
de commencer la rechercher à partir de la racine du sous arbre gauche de $n$, puis de suivre les pointeurs `fd` jusqu'à tomber 
sur un noued qui n'a pas de `fd` (ce sera bien $m$).  
Le noeud $n$ peut ensuite être modifié pour prendre la valeur de $m$ et c'est le noeud $m$ que l'on va supprimer réellement.

```c
void supprimer(ABR* ab, int val) {
    if(!*ab) return;
    if((*ab)->valeur > val) return supprimer(&((*ab)->fg), val)
    if((*ab)->valeur < val) return supprimer(&((*ab)->fd), val)
    
    // On est sur le noeud à supprimer
    
    if((*ab)->fd == NULL) {
        Noeud* tmp = (*ab)->fg;
        free(*ab);
        *ab = tmp;
        return;
    }


    if((*ab)->fg == NULL) {
        Noeud* tmp = (*ab)->fd;
        free(*ab);
        *ab = tmp;
        return;
    }

    // On va travailler avec le max du sous arbre gauche
    // Mais travailler avec le min du sous arbre droit est vrai aussi

    Noeud** curr = &((*ab)->fg)
    while((*curr)->fd) {
        curr = &((*curr)->fd);
    }
    (*ab)->valeur = (*curr)->valeur;
    supprimer(curr, (*curr)->valeur); // On entrera dans le cas où le fils droit est NULL
}
```
