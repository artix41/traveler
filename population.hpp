#ifndef POPULATION_HPP_INCLUDED
#define POPULATION_HPP_INCLUDED
#include <vector>
#include "individual.hpp"

class Population : public std::vector<Individual> {
public:
    void sort();
    Individual choose();
    void selection();

};

#endif // POPULATION_HPP_INCLUDED
