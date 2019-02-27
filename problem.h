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
  problem(size_t popSize=DEF_N, size_t genSize=DEF_GENSIZE, genType _type=DEF_TYPE);
  void killAndReplace();    //IMPLEMENT, CHOOSES WHO TO KILL AND FILLS THE SPACE BY BREEDING OTHER INDIVIDUALS USING BREEDER CONSTRUCTER
  
  static size_t n=DEF_N;
  vector<individual> population;
};


#endif //GENOOB_PROBLEM_H
