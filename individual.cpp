//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "individual.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
individual::individual() {
    binary=new bool[genLength];
}

individual& individual::operator=(const individual &other) {
    this->binary=other.binary;
}


individual::individual(const void *data) {
    switch(type){
        case BINARY:
            binary=new bool[genLength];
            memcpy(binary,data,genLength);
            break;
    /*
        case VALUE:
            value=new VAL[genLength];
            memcpy(value,data,genLength);
            break;
        case GRAPH:
            //   root=&(*((Node*)data));
            break;
 */
    }
    score=eval();
}


void individual::mutate(){
    switch(type){
        case BINARY:
            binaryMutate(binary, genLength, mutRate);
            break;
    /*
        case VALUE:
            valueMutate(value, genLength, mutRate);
            break;

        case GRAPH:
            graphMutate(root, mutRate);
            break;
    */
        }
    score=eval();
}




individual::individual(const individual* mom, const individual* dad){
    switch(type){
        case BINARY:
            binary=binaryBreed(mom->binary, dad->binary, genLength);
            break;
        /*
            case VALUE:
            value=valueBreed(mom.value, dad.value, genLength);
            break;

            case GRAPH:
            root=binaryBreed(mom.root, dad.root);
            break;
            */
    }
    for(int i=0 ; i<DEF_LENGTH ; i++){
        //cout<<mom.binary[i]<<" ";
    }

    score=eval();
}
individual::~individual() {
    switch(type){
        case BINARY:
            delete binary;
            break;
        //case VALUE:
        //    delete value;
       //     break;
       // case GRAPH:
       //     delete root;
       //     break;
    }
}


bool* binaryBreed(bool* mom, bool* dad, size_t length){
    int first_gene; //Index of the first gene to be changed.
    int last_gene; //Index of the last gene to be changed.
    int mom_or_dad; //0 or 1, To make breeding symmetric.
    bool* child;
    child = new bool[DEF_LENGTH];

    for(int i=0 ; i<DEF_LENGTH ; i++){
        //cout<<mom[i]<<" ";
    }

    srand(time(NULL));
    first_gene=rand()%DEF_LENGTH-1;
   // last_gene=rand()%DEF_LENGTH-1;
    mom_or_dad =rand() %2;


    //cout<<first_gene<<" "<<last_gene<<" "<<mom_or_dad<<endl;

    for(int i=0 ; i<DEF_LENGTH ; i++){
        if(mom_or_dad==0){
            if(i>=first_gene /*&& i<=last_gene*/){
                child[i]=mom[i];
               // cout<<mom[i]<<" "<<child[i]<<" "<<endl;
            } else {
                child[i]=dad[i];
            }
        } else {
            if(i>=first_gene /*&& i<=last_gene*/){
                child[i]=dad[i];
            } else {
                child[i]=mom[i];
               // cout<<mom[i]<<" "<<child[i]<<" "<<endl;
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
    int bingo=rate*DEF_LENGTH;
    int draw;

    toMutate=rand() %DEF_LENGTH-1;
    draw=rand() &DEF_LENGTH-1;
    if(draw<=bingo){
        *(gene+toMutate)=!*(gene+toMutate);
    }
}

double individual::eval(){
    int count=0;
    for(int i=0; i<DEF_LENGTH; i++)
    {
        count+=(binary[i]);
    }
    return count;
}