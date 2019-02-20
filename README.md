# Genoob
Genetic Algorithm workplace for the "noober" BOUN Hashcode team

Initial proposition for the software architecture is as follows:

Components{
  Generic problem template with:
    Evaluator,
    Cross-over operator(Breeder),
    Random Initializer;
  Random Number Generator;
  Random Mutator;
  Random Killer(Selecting better options according to Boltzmann's Distribution);
  Tools to set parameters dynamically;
  }
