#include "biblioH.h"
#include "biblioLC.h"

#include "entreeSortieH.h"
#include "entreeSortieLC.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    FILE* f = fopen("Valeurs.txt", "w");
    FILE* fH = fopen("ValeursH.txt", "w");
    Biblio* b;
    BiblioH* bH;
    clock_t start;
    clock_t end;
    double cpu_time_use;
    printf("Nos recherches seront faites sur GdeBiblio.txt\n");
    for(int i=1000;i<50000;i+=100){
        b = charger_n_entrees("GdeBiblio.txt", i);
        bH = charger_n_entreesH("GdeBiblio.txt", i, i/2);
        
        start = clock();
        recherche_doublonsH(bH);
        end = clock();
        cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fH,"%d\t%f\n",i,cpu_time_use);
        
        start = clock();
        recherche_doublons(b);
        end = clock();
        cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(f,"%d\t%f\n",i,cpu_time_use);

    }
    fclose(f);
}
        