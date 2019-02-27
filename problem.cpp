//
// Created by Adil Numan Celik on 27.02.2019.
//

#include "problem.h"
#include "stdio.h"
#include "math.h"
#include "gnrandom.h"
   problem:: problem(){//size_t popSize, size_t genSize, genType _type){
       //  popSize=DEF_N; genSize=DEF_LENGTH; type=DEF_TYPE;


         generateRandomPopulation();
         int i=0;
         while(i<10){
            killAndReplace();
            i++;
         }
    }

    void problem:: generateRandomPopulation() {
         srand(time(NULL));
         bool tr = true;
         bool fa = false;
         for (int i = 0; i < DEF_N; i++) {
             for (int j = 0; j < DEF_LENGTH; j++) {
                int boole = rand() % 1;
                if (boole == 1) {
                    population[i]->binary[j] = tr;
                } else {
                    population[i]->binary[j] = fa;
                }

            }
        }
    }


    void problem::killAndReplace() {
        srand(time(NULL));
        double t = 0, cumSum[n], rnd;
        int victim=-1;

        for (int i = 0; i < n; i++) {    //find temperature(coefficient of distribution)
            t += population[i]->score;
        }
        t /= n;

        for (int i = 1; i < n; i++) {    //assign all members a range proportional to the random weight
            cumSum[i] = cumSum[i - 1] + exp(-(population[i]->score) / t);
        }

        rnd = gnrandf(cumSum[n - 1]);//generate a random number in the whole range

        //find whose interval is it in (I'll do first in O(n) then someone may write binary search(O(logn)))
        for (int i = 0; i < n; i++) {
            if (rnd < cumSum[i]) {
                victim = i;
                break;
            }
        }


        //Choose mom and dad
        int a = victim;
        while (a == victim) a = rand()%n;

        int b = victim;
        while (b == victim) b = rand()%n;

        //Replace victim with a child of lucky mom and dad
        delete population[victim];
        population[victim] = new individual(population[a], population[b]);
    }

    double problem::bestScore() {
        double max = 0.0;
        for (int i = 0; i < n; i++) {
            double score = population[i]->score;
            if (score > max) {
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
