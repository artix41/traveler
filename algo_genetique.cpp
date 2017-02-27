#include <vector>
#include<iostream>
#include <algorithm>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
using namespace std;

bool compare(Individual* individual1, Individual* individual2){
    return(*individual1<*individual2);
}

void geneticAlgo(Population & population, int nbGeneration, int loozerFactor) {
  int nbLoozer = population.size()/loozerFactor;
  for(unsigned int i=0; i<population.size(); i++) {
    population[i]->evaluate();
  }

  for(int geneIndex=0; geneIndex<nbGeneration; geneIndex++){
    // if ((100*geneIndex)%nbGeneration == 0){
    //   std::cout << 100*geneIndex/nbGeneration << " "<< population[0]->get_fitness()<< " "<< population[450]->get_fitness() << '\n';
    // }
    sort(population.begin(),population.end(),compare);
    population.selection(0);

    for(int i=0; i<nbLoozer; i++) {
      Individual* father = population.choose(population.size()-nbLoozer);
      Individual* mother = population.choose(population.size()-nbLoozer);
      if (rand()%2==0){
        population[population.size()-nbLoozer+i]->crossOver2(father,mother);
      }
      else{
        population[population.size()-nbLoozer+i]->crossOver2(father,father);
      }
      for (int j = 0; j<1; j++){
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
      population[i]->mutation2();
    }
  }
  sort(population.begin(),population.end(),compare);
}
