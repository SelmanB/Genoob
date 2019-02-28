//
// Created by selman on 28.02.2019.
//

#include "individual.h"

void binaryMutate(bool* gene, size_t length, double rate){
    double r=gnrandf(1.0);
    int ind=0;
    while(r<rate){
        r=gnrandf(1.0);
        ind=rand%size;
        gene[ind] = gene[ind] != true;
    }

}
