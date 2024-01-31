#include "tab.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define MAX 10

int main(int argc, char** argv) {

    FILE* f = fopen(argv[1], "w");
    srand(time(NULL));
    clock_t init;
    clock_t end;
    double time;
    
    int* tab;
    for(int i=10; i<SIZE; i++) {
        tab = alloue_tableau(i);
        remplir_tableau(tab, i, (int)(SIZE*1.5));
        fprintf(f, "%d ", i);
        
        init = clock();
        sumOn2(tab, i);
        end = clock();
        time = ((double) end-init)/CLOCKS_PER_SEC;
        fprintf(f, "%f ", time);
        
        init = clock();
        sumOn(tab, i);
        end = clock();
        time = ((double) end-init)/CLOCKS_PER_SEC;
        fprintf(f, "%f\n", time);

    }

    fclose(f);
    return 0;
}
