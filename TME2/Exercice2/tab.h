#ifndef TAB_H
#define TAB_H

int* alloue_tableau(int n);
void desalloue_tableau(int* tab);

void remplir_tableau(int* tab, int size, int max);

void afficher_tableau(int* tab, int size);

int power(int a, int b);
int sumOn2(int* t, int size);

int sumOn(int* t, int size);

#endif
