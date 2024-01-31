#ifndef MAT_H
#define MAT_H

#define MAT(I,J,N) I+J*N  

int* alloue_matrice(int n);
void desalloue_matrice(int* mat);

void remplir_matrice(int* mat, int size, int max);
void afficher_matrice(int* mat, int size);

#endif
