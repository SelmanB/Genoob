//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "gnrandom.h"
int gnrandi(int max){
    int r=-1;
    srand(time(NULL));
    r=rand()%max;
    return r;
}

double gnrandf(float max){
    return (0.0+gnrandi(INT_MAX)/(float)INT_MAX);


}