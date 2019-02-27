//
// Created by selman on 24.02.2019.
//

#ifndef GENOOB_PROBLEM_H
#define GENOOB_PROBLEM_H

#include "individual.h"
#include <vector.h>
using namespace std;

#define DEF_N 100

class problem{
public:
  problem(size_t popSize=DEF_N, size_t genSize=DEF_LENGTH, genType _type=DEF_TYPE);
  void killAndReplace();    //IMPLEMENT, CHOOSES WHO TO KILL AND FILLS THE SPACE BY BREEDING OTHER INDIVIDUALS USING BREEDER CONSTRUCTER
                            //USE PROBABILITY TO LIVE ACCORDING TO BOLTZMANN's DISTRIBUTION(EXPONENTIALLY)
  void printBest();         //IMPLEMENT LATER, PROBLEM SPECIFIC
  double bestScore();       //IMPLEMENT,easy
  void printScores();       //IMPLEMENT,easy
  static size_t n=DEF_N;
  individual *population;
};


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
#endif //GENOOB_PROBLEM_H
