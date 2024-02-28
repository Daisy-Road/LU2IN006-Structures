# Exercice 1

## Question 1

Un arbre est une structure de donnéespermettant de manipuler des ensemble d'éléments quelconque.  
Il est caractérisé par un élément racine, des éléments intermédiaires et des feuilles. Ces éléments
sont appelés des noeuds de l'arbre.  

Un arbre est dit:
- Binaire: si chaque noeud possède <u>au plus</u> 2 fils.
- Complet: si tous les niveaux sauf le dernier sont remplis.
- Tassé à gauche: si les feuilles sont stockées de gauche à droite.

Un tas est un ensemble d'éléments auxquels sont associés des clés (des entiers en pratique)
structuré en un arbre binaire complet tassé à gauche et tel que tout noued possède une clé plus grande
que celle de son père.

## Question 2

On insère les éléments sur la gauche en premier. On vérifie que l'élément inséré à une clé plus 
grande que celle de son père. Si ce n'est pas le cas, on fait un swap et on vérifie si le changement 
reste valide jusqu'à la racine si nécéssaire.  

![img](708.jpg)

## Question 3

Le plus petit élément est à la racine du tas. Pour garder la structure de tas et garantir que l'arbre 
est complet. On commence par remplacer la racine par le dernier élément (Element le plus à droite du 
niveau le plus bas). Ensuite on effectue des swap à partir de la racine pour garantir que les clés 
sont bien ordonnées.

![img](709.jpg)

## Question 4

- Pour $h=0$: $0 \leq n \leq 1$
- Pour $h=1$: $0+2 \leq n \leq 1+2$
- Pour $h=2$: $0+2+2 \leq n \leq 1+2+4$
- ...
- Pour $h$: $2^h \leq n \leq \sum_{i=0}^n2^i = 2^{n+1}-1$

## Question 5

D'une part: $$2^h \leq n \Leftrightarrow log_2(2^h) \leq log_2(n) \Leftrightarrow h \leq log_2(n)$$
D'autre part: $$n \leq 2^{h+1}-1 \Leftrightarrow n+1 \leq 2^{h+1} \Leftrightarrow log_2(n+1) \leq h-1 \Leftrightarrow h \geq log_2(n+1)$$

On a donc que:
$$log_2(n+1) -1 \leq h \leq log_2(n)$$

Or puisque $h$ est un entier, on peut écrire que: $\lceil log_2(n+1)-1 \rceil \leq h \leq \lfloor log_2(n) \rfloor$   
Démontrons que $log_2(n) -log_2(n+1) + 1 < 1$  

Reecrivons la propriété à démontrer...  
$$log_2(n) - log_2(n+1) + 1 < 1 \Leftrightarrow log_2(n) - log_2(n+1) < 0 \Leftrightarrow log(\frac{n}{n+1}) < 0$$

Comme $n < n+1$ la dernière inégalité est une trivialité.  
On a donc forcément: $\lceil log_2(n+1)-1 \rceil = \lfloor log_2(n) \rfloor = h$

## Question 6

En rajoutant, un élément ayant une clé plus petite que tous les éléments du tas, nous serions obligé 
de faire $h$ swap d'éléménets avant que la nouveille feuille remplace la racine. Sachant que $h = log_2(n)$,
ceci correspond au coût le plus élevé pour une insertion. L'insertion est donc $O(log_2(n))$.  
Pour la suppression du minimum, on retrouve la même complexité, car dans le pire cas, on devra faire $h$
swaps de la racine vers une feuille.
