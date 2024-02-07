# Exercice 2

## Q.2.1

On cherche alors la valeur du nombre du chiffre des unités (car on y applique la fonction `g`).
1 - 14
2 - 8
3 - 3
4 - 5
5 - 1
6 - 8
7 - 4
8 - 4
9 - 6
10 - 8
11 - 5
12 - 5
13 - 4

Car en base hexadécimal, si on applique le modulo 16, cela revient à seulement considérer le chiffre des unités.

## Q.2.2

Rappellons que les fonctions de probing font une tentative pour i=0 et incrémente le i en cas d'échec.  

On écrit x -> y se traduit par x est suivi de y dans la liste chaînée  
On écrit Cx => Cy la tentantive de placement en case Cx qui résulte en un échec et qui passe à Cy
| Cases  | chaînage | probing linéaire | probing quadratique | 
|--------|---|---|---|
| C0 | - | - | 13 (C4 => C5 => C7 => C10 => C14 => C3 => C9 => C0) |
| C1 | 05 | 05 | 05 |
| C2 | - | - | - |
| C3 | 03 | 03 | 03  |
| C4 | 07 -> 08 -> 13 | 07 | 07 |
| C5 | 04 -> 11 -> 12 | 04 | 04 |
| C6 | 09 | 08 (C4 => C5 => C6) | 09 |
| C7 | - | 09 (C6 => C7) | 08 (C4=>C5=>C7) |
| C8 | 02 -> 06 -> 10 | 02 | 02 |
| C9 | - | 06 (C8 => C9) | 06 (C8=>C9) |
| C10 | - | 10 (C8 => C9 => C10) | 12 (C5 => C6 => C8 => C11 => C15 => C4 => C10) |
| C11 | - | 11 (C5 => C6 => C7 => C8 => C9 => C10 => C11) | 10 (C8=>C9=>C11) |
| C12 | - | 12 (C5 => C6 => C7 => C8 => C9 => C10 => C11 => C12)| - |
| C13 | - | 13 (C4 => C5 => C6 => C7 => C8 => C9 => C10 => C11 => C12 => C13)| - |
| C14 | 01 | 01 | 01 |
| C15 | - | - | 11 (C5 => C6 => C8 => C11 => C15) |

Pour le probing linéaire, le nombre de tentative d'insertion moyen causant un échec est 28/3 et pour celui quadratique 22/13.  
Le probing quadratique est meilleur dans ce cas.  
