#include <vector>
#include<iostream>
#include <algorithm>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
using namespace std;

void geneticAlgo(Population & population, int nbGeneration, int loozerFactor) {
  int nbLoozer = population.size()/loozerFactor;
  for(unsigned int i=0; i<population.size(); i++) {
    population[i]->evaluate();
  }

  for(int geneIndex=0; geneIndex<nbGeneration; geneIndex++){
    sort(population.begin(),population.end(),compare);
    population.selection(population.size()-nbLoozer);

    for(int i=0; i<nbLoozer; i++){
      Individual* father = population.choose(population.size()-nbLoozer);
      Individual* mother = population.choose(population.size()-nbLoozer);
      population[population.size()-nbLoozer+i]->crossOver(father,mother);
      for (int j = 0; j<2; j++){
        population[population.size()-nbLoozer+i]->mutation();
      }
      population[population.size()-nbLoozer+i]->evaluate();
    }
  }
  sort(population.begin(),population.end(),compare);
}

bool compare(Individual* individual1, Individual* individual2){
  return(*individual1<*individual2);
}
