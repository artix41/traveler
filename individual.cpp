#include "individual.hpp"

bool operator<(Individual const & individual1, Individual const & individual2){
  return(individual1._fitness<individual2._fitness);
}

Individual::~Individual(){}

float Individual::get_fitness(){return(_fitness);}

void Individual::set_fitness(float x){_fitness = x;}
