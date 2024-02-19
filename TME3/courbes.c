#include "biblioH.h"
#include "biblioLC.h"

#include "entreeSortieH.h"
#include "entreeSortieLC.h"

#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
    FILE* f = fopen("Valeurs.txt", "w");
    FILE* fH = fopen("ValeursH.txt", "w");
    Biblio* b;
    BiblioH* bH;
    Biblio* dub;
    BiblioH* dubH;
    clock_t start;
    clock_t end;
    double cpu_time_use;
    printf("Nos recherches seront faites sur GdeBiblio.txt\n");
    for (int i = 1000; i <= 50000; i += 1000) {
        b = charger_n_entrees("GdeBiblio.txt", i);
        bH = charger_n_entreesH("GdeBiblio.txt", i, i / 2);

        start = clock();
        dubH = recherche_doublonsH(bH);
        end = clock();
        cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fH, "%d\t%f\n", i, cpu_time_use);

        start = clock();
        dub = recherche_doublons(b);
        end = clock();
        cpu_time_use = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(f, "%d\t%f\n", i, cpu_time_use);
        liberer_biblio(b);
        liberer_biblioH(bH);
        liberer_biblio(dub);
        liberer_biblioH(dubH);
        printf("Done %d/50000\n", i);
    }
    fclose(f);
    fclose(fH);
}
