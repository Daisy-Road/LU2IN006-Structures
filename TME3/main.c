#include "entreeSortieLC.h"
#include "biblioLC.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
   
    Biblio* b = charger_n_entrees(argv[1], atoi(argv[2]));
    liberer_biblio(b);
}
