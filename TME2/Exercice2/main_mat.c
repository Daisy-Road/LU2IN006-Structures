#include "mat.h"

int main(void) {
    int* mat = alloue_matrice(5);
    remplir_matrice(mat, 5, 10);
    afficher_matrice(mat, 5);
    desalloue_matrice(mat);
}
