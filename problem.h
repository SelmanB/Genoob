//
// Created by selman on 24.02.2019.
//

#ifndef GENOOB_PROBLEM_H
#define GENOOB_PROBLEM_H

#include "individual.h"
#include <vector.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define DEF_N 100

class problem{
public:
  problem(size_t popSize=DEF_N, size_t genSize=DEF_LENGTH, genType _type=DEF_TYPE);
  void killAndReplace();    //IMPLEMENT, CHOOSES WHO TO KILL AND FILLS THE SPACE BY BREEDING OTHER INDIVIDUALS USING BREEDER CONSTRUCTER
                            //USE PROBABILITY TO LIVE ACCORDING TO BOLTZMANN's DISTRIBUTION(EXPONENTIALLY)
  void printBest();         //IMPLEMENT LATER, PROBLEM SPECIFIC
  double bestScore();       //IMPLEMENTED
  int bestIndividual();      //IMPLEMENTED
  void printScores();       //IMPLEMENTED
  void generateRandomPopulation(); //FILL ARRAY OF POPULATION WİTH RANDOM INDIVIDUALS
  static size_t n=DEF_N;
  individual *population;
  
  
};

problem(size_t popSize=DEF_N, size_t genSize=DEF_LENGTH, genType _type=DEF_TYPE){
     generateRandomPopulation(genSize);
     while(){
         killAndReplace();
     }        
}

void generateRandomPopulation(int genSize){
  srand(time(NULL));
  bool tr=true;
  bool fa=false;
  for(int i=0 ; i<n ; i++){
     for(int j=0 ; j<genSize ; j++){
          int boole=rand() %1;
          if(boole==1){
            *population[i].binary[j]=tr;
          else {
            *population[i].binary[j]=fa;
          }
     }
  }
}
          

void killAndReplace(){
    double t=0,cumSum[n],rnd;
    int victim;
  
    for(int i=0;i<n;i++){    //find temperature(coefficient of distribution)
        t+=population[i]->score;
    }t/=n;
  
    for(int i=1;i<n;i++){    //assign all members a range proportional to the random weight
      cumSum[i]=cumSum[i-1]+exp((population[i]->score)/t);
    }

    rnd=gnrandf(cumSum[n-1]);//generate a random number in the whole range
                          
     //find whose interval is it in (I'll do first in O(n) then someone may write binary search(O(logn)))
  for(int i=0; i<n; i++){
       if(rnd<cumSum[i]){
            victim=i;
            break;
       }
  }

      //Choose mom and dad
  int a=victim;
  while(a==victim) a=gnrandi(n);
  
  int b=victim;
  while(b==victim) b=gnrandi(n);
  
      //Replace victim with a child of lucky mom and dad
  delete population[victim];
  population[victim]=new individual(*population[a],population[b]);
}

double bestScore(){
    double max=0.0;
    for(int i=0 ; i<n ; i++){
        double score=population[i].score; 
        if(score>max){
            max=score;
        }
    }
    return max;
}

int bestIndividual(){
    double max=0.0;
    int best;
     for(int i=0 ; i<n ; i++){
        double score=population[i].score; 
        if(score>max){
            max=score;
            best=i;
        }
    }
  return best;
}


void printScores(){
    for(int i=0 ; i<n ; i++){
        printf("%f ", population[i].score);
    }
}
#endif //GENOOB_PROBLEM_H
