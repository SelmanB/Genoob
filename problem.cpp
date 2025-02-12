//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "problem.h"
#include "stdio.h"
#include "math.h"
#include "gnrandom.h"
#include "iostream"
#include <random>
#include <iostream>
#include "queue"
using namespace std;
problem:: problem(){

    for(int i=0; i<DEF_N ; i++){
        population[i]=new individual();
    }

    generateRandomPopulation();

    int i=0;
    while(i<20000) {
        killAndReplace();
        i++;
    }

    printScores();
    double y =bestScore();

    double z=worstScore();
    cout<<endl<<y<<" "<<z;




}

void problem:: generateRandomPopulation() {

    bool tr = true;
    bool fa = false;

    for (int i = 0; i < DEF_N; i++) {
        for (int j = 0; j < DEF_LENGTH; j++) {
            double btmp = gnrandf(2.0);
            bool boole=btmp<1.0;

            if (boole) {
                population[i]->binary[j] = true;
            } else {
                population[i]->binary[j] = false;
            }
        }
        population[i]->score=population[i]->eval();
    }

}


void problem::killAndReplace() {
    double t = 0, cumSum[n], rnd;
    int victim=-1;
/*
    for (int i = 0; i < n; i++) {    //find temperature(coefficient of distribution)
        t += population[i]->score;
    }
    t /= n*1000;


    for (int i = 1; i < n; i++) {    //assign all members a range proportional to the random weight
        cumSum[i] = cumSum[i - 1] + exp(-(population[i]->score) / t);
    }

    rnd = gnrandf(cumSum[n-1]);//generate a random number in the whole range
    //cout<<rnd<<endl;
    //find whose interval is it in (I'll do first in O(n) then someone may write binary search(O(logn)))
    for (int i = 0; i < n; i++) {
        if (rnd < cumSum[i]) {
            victim = i;
            break;
        }
    }

*/
    // Yasin's distribution
    priority_queue<pair <double, int> > xx;
    for(int i=0 ; i<n ; i++){
        xx.push(make_pair(population[i]->score,i));
        if(xx.size()>15){
            xx.pop();
        }
    }
    int y=rand()%15;
    while(y--){
        xx.pop();
    }
    victim=xx.top().second;
    //Choose mom and dad
    int a = victim;

    while (a == victim) a = rand()%n;



    int b = victim;
    while (b == victim) b = rand()%n;

    //cout<<"victim: "<<victim<<" "<<a<<" "<<b<<endl;
    delete population[victim];
    population[victim] = new individual(population[a], population[b]);
}

double problem::bestScore() {
    double max = 0;
    for (int i = 0; i < n; i++) {
        double score = population[i]->score;
        if (score > max) {
            max = score;
        }
    }
    return max;
}

double problem::worstScore() {
    double max = 10000;
    for (int i = 0; i < n; i++) {
        double score = population[i]->score;
        if (score < max) {
            max = score;
        }
    }
    return max;
}

int problem:: bestIndividual() {
    double max = 0.0;
    int best=-1;
    for (int i = 0; i < n; i++) {
        double score = population[i]->score;
        if (score > max) {
            max = score;
            best = i;
        }
    }
    return best;
}


void problem::printScores() {
    for (int i = 0; i < n; i++) {
        printf("i:%f\n", population[i]->score);
    }
    //puts("\n\n");
}