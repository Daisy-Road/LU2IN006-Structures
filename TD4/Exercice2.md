# Exercice 2

## Partie 2

### Q.2.4

```c
typedef struct asso Association;

typedef struct membre {
    Association* personnePouM;
    struct membre* suiv;
} MembreAssoc;

struct asso {
    char* nom;
    char* adresse;
    MembreAssoc* listeMembres;
};
```
Chaque élément contient une liste de membre qui est non vide si et seulement si il s'agit d'une association

### Q.2.5

Une personne physique pourrait être membre de deux association, elle même membre l'un l'autre et recevoir donc 2 courriers.  
Plusieurs association peuvent former un circuit et conduire à une boucle lors de l'envoi de courrier.

### Q.2.6

Pour le premier problème, il est possible de créer une table de hachage pour vérifier si la personne n'a pas déjà reçu un courrier.
 Cela rendra les tests plus rapide.  

pour l'autre problème, on peut ajouter un champ temporaire pour savoir si l'association a déjà été visitée ou non.

### Q.2.7

La suppression brute d'un membre demande d'aller supprimer tous les pointeurs des associations qui le contiennent.  
C'est très lent si la maison des associations est grande.  

L'autre solution consite à remplacer la complexité temps par la complexité mémoire, en notant dans chaque éléments, 
la liste des éléments qui le contiennent (c'est à dire des pointeurs vers le père)
