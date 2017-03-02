#include <vector>
#include<iostream>
#include <algorithm>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
#include "path.hpp"
using namespace std;

bool compare(Individual* individual1, Individual* individual2){
    return(*individual1<*individual2);
}

void geneticAlgo(Population & population, Individual* individual, int nbGeneration, int loozerFactor) {
  int nbLoozer = population.size()/loozerFactor;
  //dynamic_cast<Path*>(population[0])->_path = {0,13,12,11,6,5,14,4,10,8,9,18,19,20,15,2,1,16,21,3,17,7};

  for(unsigned int i=0; i<population.size(); i++) {
    population[i]->evaluate();
  }

  for(int geneIndex=0; geneIndex<nbGeneration; geneIndex++){
    if ((100*geneIndex)%nbGeneration == 0){
      //std::cout << 100*geneIndex/nbGeneration << " "<< population[0]->get_fitness()<< " "<< population[population.size()-nbLoozer-1]->get_fitness() << '\n';
    }
    sort(population.begin(),population.end(),compare);
    population.selection(0);

    for(int i=0; i<nbLoozer; i++) {
      Individual* father = population.choose(population.size()-nbLoozer);
      Individual* mother = population.choose(population.size()-nbLoozer);
      if (rand()%2==-1){
        population[population.size()-nbLoozer+i]->crossOver2(father,father);
      }
      else{
        population[population.size()-nbLoozer+i]->crossOver2(father,mother);
      }
      for (int j = 0; j<10; j++){
        if(rand()%7==0){
          population[population.size()-nbLoozer+i]->mutation();
        }
      }
      population[population.size()-nbLoozer+i]->evaluate();
      for (unsigned int j = 0; j<population.size()-nbLoozer; j++){
        if (population[population.size()-nbLoozer+i]->get_fitness() == population[j]->get_fitness()){
          i--;
          j = population.size()-nbLoozer;
        }
      }
    }
    for(unsigned int i = 0; i<population.size(); i++){
      individual->crossOver2(population[i], population[i]);
      individual->set_fitness(population[i]->get_fitness());
      population[i]->mutation_locale(1);
      for (unsigned int j = 0; j<i; j++){
        if (population[i]->get_fitness() == population[j]->get_fitness()){
          population[i]->crossOver2(individual, individual);
          population[i]->set_fitness(individual->get_fitness());
          j = i;
        }
      }
    }
  }
  sort(population.begin(),population.end(),compare);
}
