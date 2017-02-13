#include <vector>
#include<iostream>
#include <algorithm>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
using namespace std;

void geneticAlgo(Population* population, int nbGeneration, int nbLoozer) {
    std::cout << "Start geneticAlgo" << '\n';
    for(int i = 0; i < (int) population->size(); i++) {
        (*population)[i]->evaluate();
    }

    for(int geneIndex=0; geneIndex<nbGeneration; geneIndex++){
        sort(population->begin(),population->end(),compare);
        population->selection(population->size()-nbLoozer);

        for(int i=0; i<nbLoozer; i++){
            Individual* father = population->choose2(population->size()-nbLoozer);
            Individual* mother = population->choose2(population->size()-nbLoozer);
            (*population)[population->size()-nbLoozer+i]->crossOver(father,mother);
            (*population)[population->size()-nbLoozer+i]->evaluate();
        }
    }

    std::cout << "End geneticAlgo" << '\n';
}

bool compare(Individual* individual1, Individual* individual2){
    return(*individual1<*individual2);
}
