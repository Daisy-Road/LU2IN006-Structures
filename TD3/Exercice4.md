# Exercice 4

## Q.4.4

Supprimer un élément dans une table de hachage avec résolution des collisions par chaînage revient à supprimer un élément d'une liste chaînée.  
Dans le pire cas, cette opération s'effectue en O(n) avec n le nombre total d'éléments.  
Il est bien plus efficace de remplacer la liste chaînée par un arbre binaire de recherche, les clefs permettant le tri des éléments, 
de façon à retrouver la clé à supprimer en O(log(n)) dans le pire cas.
