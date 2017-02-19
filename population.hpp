#ifndef POPULATION_HPP_INCLUDED
#define POPULATION_HPP_INCLUDED
#include <vector>
#include "individual.hpp"
using namespace std;

class Population : public vector<Individual*> {
public:
    ~Population();
    Individual* choose(int);
    Individual* choose2(int, int);
    void selection2(int, int);
    void selection(int);
};

#endif // POPULATION_HPP_INCLUDED
