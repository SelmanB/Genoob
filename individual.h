//
// Created by selman on 24.02.2019.
//

#ifndef GENOOB_INDIVIDUAL_H
#define GENOOB_INDIVIDUAL_H
#include <cstring>
#include "node.h"
#include "gnrandom.h"

enum genType {BINARY,VALUE,GRAPH};



#define VAL float
#define DEF_TYPE BINARY
#define DEF_LENGTH 2000
#define DEF_MUT_RATE 0.01


class individual: public problem{
public:

    individual();                                                   //default initializer e.g. random or greedy IMPLEMENT EACH TIME
    individual(const void* data);                                   //İnitializer with data
    individual(const individual& mom, const individual& dad);       //Breeding IMPLEMENT ONCE
    mutate();                                                       //
    double eval();                                                  //IMPLEMENT EACH TIME


    static genType type=DEF_TYPE;
    static size_t genLength=DEF_LENGTH;
    static double mutRate=DEF_MUT_RATE;


    bool* binary;
    VAL *value;
    Node *root;
    double score=0;
};


individual::individual(const void *data) {
    switch(type){
        case BINARY:
            binary=new bool[genLength];
            memcpy(binary,data,genLength);
            break;
        case VALUE:
            value=new VAL[genLength];
            memcpy(value,data,genLength);
            break;
        case GRAPH:
            //   root=&(*((Node*)data));
            break;
    }
    score=eval();
}


individual::mutate(){
    switch(type){
        case BINARY:
            binaryMutate(binary, genLength, mutRate);
            break;
        case VALUE:
            valueMutate(value, genLength, mutRate);
            break;
        case GRAPH:
            graphMutate(root, mutRate);
            break;
    }
    score=eval();
}




individual::individual(const individual& mom, const individual& dad){
    switch(type){
        case BINARY:
            binary=binaryBreed(mom.binary, dad.binary, genLength);
            break;
        case VALUE:
            value=valueBreed(mom.value, dad.value, genLength);
            break;
        case GRAPH:
            root=binaryBreed(mom.root, dad.root);
            break;
    }
    score=eval();
}




//***************IMPLEMENT ONCE********************

void binaryMutate(bool* gene, size_t length, double rate);

void valueMutate(VAL *gene, size_t length, double rate);

void graphMutate(Node *root, double rate);



bool* binaryBreed(bool* mom, bool* dad, size_t length);

VAL* valueBreed(VAL* mom, VAL* dad, size_t length);

node* graphBreed(node* mom, dad* dad);



#endif //GENOOB_INDIVIDUAL_H
