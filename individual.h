//
// Created by Adil Numan Celik on 27.02.2019.
//

#ifndef GENOOBB_INDIVIDUAL_H
#define GENOOBB_INDIVIDUAL_H


#include <cstring>
//#include "Node.h"
#include <stdlib.h> //For random
#include <time.h> //For random

enum genType {BINARY,VALUE,GRAPH};



#define VAL float
#define DEF_TYPE BINARY
#define DEF_LENGTH 2000
#define DEF_MUT_RATE 0.005



class individual{
public:

    individual();
    individual &operator=(const individual& other);//default initializer e.g. random or greedy IMPLEMENT EACH TIME
    individual(const void* data);                                   //İnitializer with data
    individual(const individual* mom, const individual* dad);       //Breeding IMPLEMENT ONCE
    void mutate();                                                       //
    double eval();                                                  //IMPLEMENT EACH TIME
    ~individual();
    bool rswap(bool input);

    const genType type=DEF_TYPE;
    const size_t genLength=DEF_LENGTH;
    const double mutRate=DEF_MUT_RATE;

    bool* binary;
    VAL *value;
   // Node *root;
    double score=0;
};








//***************IMPLEMENT ONCE********************

void binaryMutate(bool* gene, size_t length, double rate);

void valueMutate(VAL *gene, size_t length, double rate);

//void graphMutate(Node *root, double rate);



bool* binaryBreed(bool* mom, bool* dad, size_t length);

VAL* valueBreed(VAL* mom, VAL* dad, size_t length);

//Node* graphBreed(Node* mom, Node* dad);

#endif //GENOOBB_İNDİVİDUAL_H
