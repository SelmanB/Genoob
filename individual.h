//
// Created by selman on 24.02.2019.
//

#ifndef GENOOB_INDIVIDUAL_H
#define GENOOB_INDIVIDUAL_H
#include <cstring>
#include "node.h"
#include "gnrandom.h"
#include <stdlib.h> //For random
#icnlude <time.h> //For random

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

/*
binaryBreed implemented.
Basically creates two random indexes and mixes the genes of mom and dad.
*/
bool* binaryBreed(bool* mom, bool* dad, size_t length){
    int first_gene; //Index of the first gene to be changed.
    int last_gene; //Index of the last gene to be changed.
    int mom_or_dad; //0 or 1, To make breeding symmetric.
    bool* child;
    child = new bool[genLength];

    srand(time(NULL));
    first_gene=rand()%genLength-1;
    second_gene=rand()%genlength-1;
    mom_or_dad =rand() %1;
    
    for(int i=0 ; i<genLength ; i++){
       if(mom_or_dad==0){
           if(i>=first_gene && i<=last_gene){
               *(child+i)=*(mom+i);
           } else {
               *(child+i)=*(mom+i);
           }
       } else {
           if(i>=first_gene && i<=last_gene){
               *(child+i)=*(dad+i);
           } else {
               *(child+i)=*(mom+i);
           }
       }

    }
    return child;
}

/*
Mutates a random gene with a probability of rate.
*/

void binaryMutate(bool* gene, size_t length, double rate){
    srand(time(NULL));
    int toMutate;
    int bingo=rate*genLength;
    int draw;

    toMutate=rand() %genLength-1;
    draw=rand() &genLength-1;
    if(draw<=bingo){
        *(gene+toMutate)=!*(gene+toMutate);
    }
}





//***************IMPLEMENT ONCE********************

void binaryMutate(bool* gene, size_t length, double rate);

void valueMutate(VAL *gene, size_t length, double rate);

void graphMutate(Node *root, double rate);



bool* binaryBreed(bool* mom, bool* dad, size_t length);

VAL* valueBreed(VAL* mom, VAL* dad, size_t length);

node* graphBreed(node* mom, dad* dad);



#endif //GENOOB_INDIVIDUAL_H
