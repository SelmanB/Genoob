//
// Created by selman on 26.02.2019.
//

#ifndef GENOOB_GNRANDOM_H
#define GENOOB_GNRANDOM_H

#include <stdlib.h>
#include <time.h>

int gnrandi(int max);

double gnrandf(float max){
    return (0.0+gnrandi(INT_MAX)/(float)INT_MAX)


}


#endif //GENOOB_GNRANDOM_H
