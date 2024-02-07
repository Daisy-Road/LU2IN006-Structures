# Exercice 1

## Q.1.1

Il s'agit d'une association (clé, valeur) où la clé est une empreinte digitale et la valeur est la fiche personnel de l'individu.  
Une table de hachage semble donc être une bonne alternative.  

## Q.1.2

La fonction de hachage s'applique sur les clé et donne la position des éléments dans le tableau. Comme le tableau a une taille
a une taille de 10^5, la fonction de hachage doit retourner une valeur module 10^5.

## Q.1.3

Les entiers étant compris entre 0 et 99, l'ensemble des vecteurs contenant un 0 seraient stockées dna sla meêm case, la case 0.  
Pour diminuer le taux de collision, on peut contourner ce problème en rajoutant une unité à 
chaque composant du vecteur avant d'en effectuer son produit.

```c
int g(int x1, int x2, int x3, int x4, int x5, int x6) {
    return (x1+1)*(x2+1)*(x3+1)*(x4+1)*(x5+1)*(x6+1)%100000
}
```

## Q.1.4

Ces entrées ont toutes les mêmes valeurs de hachage, en utilisant la fonction de hachage précédente.  
Il nous faut une fonction pour gérer les collisions.
