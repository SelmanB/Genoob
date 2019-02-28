//
// Created by Adil Numan Celik on 27.02.2019.
//

#ifndef GENOOBB_PROBLEM_H
#define GENOOBB_PROBLEM_H

#include "individual.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define DEF_N 100
#define DEF_LENGTH 2000

static size_t n=DEF_N;

class problem{
public:
    problem();//size_t popSize, size_t genSize, genType _type);
    individual* population[DEF_N];
    void killAndReplace();    //IMPLEMENT, CHOOSES WHO TO KILL AND FILLS THE SPACE BY BREEDING OTHER INDIVIDUALS USING BREEDER CONSTRUCTER
    double worstScore();// USE PROBABILITY TO LIVE ACCORDING TO BOLTZMANN's DISTRIBUTION(EXPONENTIALLY)
    void printBest();         //IMPLEMENT LATER, PROBLEM SPECIFIC
    double bestScore();       //IMPLEMENTED
    int bestIndividual();      //IMPLEMENTED
    void printScores();       //IMPLEMENTED
    void generateRandomPopulation(); //FILL ARRAY OF POPULATION WİTH RANDOM INDIVIDUALS




};



#endif //GENOOBB_PROBLEM_H
