# Genoob

*****TODO:IMPLEMENT INDIVIDUAL.H FUNCTIONS

*****TODO:DEFINE PROBLEM.H ARCHITECTURE* e.g. How to choose who to kill and breed 
          
          

Genetic Algorithm workplace for the "noober" BOUN Hashcode team

Library books on "Computational Intelligence" provide plenty of information on the algorithm and its alternatives. This also looks useful: http://www.obitko.com/tutorials/genetic-algorithms/index.php

Initial proposition for the software architecture is as follows:



Components{

  Generic problem template with:

    Evaluator,
    
    Cross-over operator(Breeder),
    
    Random Initializer;
      
    Random Mutator*;   --rate parameter
  
  Random Number Generator;
  
  Random Killer(Selecting better options according to Boltzmann's Distribution*);    --Temperature parameter
  
  <advanced>Tools to set parameters(Mutation rate and temperature) dynamically;
  
  }
  
  

  Or...
  
  Some previously written libraries for genetic algorithm include:
  
  http://jenetics.io/
  
  http://lancet.mit.edu/ga/

*proportional to exp[fk] where f is the fitness function and k is the inverse temperature coefficient. 

*With crossover disabled and this set to a high rate, the algorithm automatically becomes a "Simulated Annealing" algorithm

It will probably be better to code in c++ and make the program such that the current progress will be printed in a file upon termination of the program. 
