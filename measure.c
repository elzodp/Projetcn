#include <err.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queens.h"
#include "rdtsc.h"




 /* usage: mesure de performance pour differentes valeures de n
  */
#ifndef CMOCKA_H_
int main(int argc, char *argv[]) {
    FILE* fp=NULL;
    fp=fopen("cycle.txt","wb");
    if(!fp)
    {   
        printf("erreur d'ouverure de fichier\n");
        exit(EXIT_FAILURE);  
    }
    
    for(int i=1; i<20; i++)
    {   
        int queen_row[i];
        unsigned long long before = rdtsc();
        for(int j = 0; j < 15; j++)
            find_solution(i, queen_row);
        unsigned long long after = rdtsc();
        fprintf(fp, "%llu\n", (after - before) / 10);
    }
    
    fclose(fp);

    return 0;
}
#endif
