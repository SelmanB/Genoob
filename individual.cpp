//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "individual.h"
#include "stdlib.h"
#include "iostream"
#include "gnrandom.h"
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
            mutate();
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
bool rswap(bool input){
    int r=rand()%100;
    if(r==0)return !input;
    else return input;
}

bool* binaryBreed(bool* mom, bool* dad, size_t length){
    int mom_or_dad; //0 or 1, To make breeding symmetric.
    bool* child;
    child = new bool[DEF_LENGTH];
    //int x=0;
    bool par=true;

    for(int i=0;i<DEF_LENGTH;i++){
        par=rswap(par);
        if(par)child[i]=mom[i];
        else child[i]=dad[i];
    }
    /*
    for(int i=0 ; i<DEF_LENGTH ; i++) {



        if (rand() % 200 == 0) {
            child[i] = rand() % 2;
            continue;
        }
        if (mom_or_dad == 0) {
            if (rand() % 500 == 0) {
                mom_or_dad = 1;
                child[i] = dad[i];
            } else {
                child[i] = mom[i];
            }
        } else {
            if (rand() % 500 == 0) {
                mom_or_dad = 0;
                child[i] = mom[i];
            } else {
                child[i] = dad[i];
            }
        }
    }



        if(rand()%200==0){
            child[i]=rand()%2;
            continue;
        }
        mom_or_dad =rand() %2;
        if(mom_or_dad==0){
           child[i]=mom[i];
           /* if(i>=first_gene && i<=last_gene){
                child[i]=mom[i];
                // cout<<mom[i]<<" "<<child[i]<<" "<<endl;
            } else {
                child[i]=dad[i];
            }

        } else {
            child[i]=dad[i];
            /*
            if(i>=first_gene && i<=last_gene){
                child[i]=dad[i];
            } else {
                child[i]=mom[i];
                // cout<<mom[i]<<" "<<child[i]<<" "<<endl;
            }
             */



    return child;
}

void binaryMutate(bool* gene, size_t length, double rate){
    double r=gnrandf(1.0);
    int ind=0;
    while(r<rate){
        r=gnrandf(1.0);
        ind=rand()%length;
        gene[ind] = gene[ind] != true;
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