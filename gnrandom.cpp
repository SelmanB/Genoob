//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "gnrandom.h"
#include <random>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define _MAX 100
int gnrandi(int max){

    //srand(time(NULL));
    return rand()%max;
    /*std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double x= dist(mt)*max;
    return (int) x;*/
}

double gnrandf(float max){

    int imax = (int) max*1000.0;
    return ( (rand()%imax) / 1000.0 );
    /*std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, max);
    return dist(mt);*/

}