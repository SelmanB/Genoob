//
// Created by selman on 28.02.2019.
//

#include "individual.h"

#define SWAP 100


bool rswap(bool input){
    int r=rand()%SWAP;
    if(r==0)return !input;
    else return input;
}


bool* binaryBreed(const bool* mom, const bool* dad, size_t size){
    bool *child;
    child=new bool[size];
    bool par=true;

    for(int i=0;i<size;i++){
        par=rswap(par);
        if(par)child[i]=mom[i];
        else child[i]=dad[i];
    }


}