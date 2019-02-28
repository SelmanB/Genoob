//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "gnrandom.h"
#include <random>
#include <iostream>
#define _MAX 100
int gnrandi(int max){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    double x= dist(mt)*max;
    return (int) x;
}

double gnrandf(float max){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, max);

    return dist(mt);

}