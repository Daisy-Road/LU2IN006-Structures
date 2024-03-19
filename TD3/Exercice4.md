# Exercice 4

## Q.4.1

On définit:
```c
typedef struct _Cell {
    int value;
    struct _Cell* suiv;
} Cell;

Element** createHash(int size) {
    Element** hash = (Element**) malloc(size*sizeof(Element*));
    for(int i= 0; i < size; i++) {
        hash[i] = NULL;
    }
    return hash;
}

```

## Q.4.2

On donne le code suivant
```c
void store(Cell** hashTable, int size, int val) {
    int hash = (g(val)%size);
    Cell* newCell = (Cell*) malloc(sizeof(Cell));
    newCell->value = val;
    newCell->suiv = hashTable[hash];
    hashTable[hash] = newCell;
}
```

## Q.4.3

On donne
```c
typedef struct _hash {
    int nbElem;
    Cell** table
} Hash
```

## Q.4.4

Supprimer un élément dans une table de hachage avec résolution des collisions par chaînage revient à supprimer un élément d'une liste chaînée.  
Dans le pire cas, cette opération s'effectue en O(n) avec n le nombre total d'éléments.  
Il est bien plus efficace de remplacer la liste chaînée par un arbre binaire de recherche, les clefs permettant le tri des éléments, 
de façon à retrouver la clé à supprimer en O(log(n)) dans le pire cas.
