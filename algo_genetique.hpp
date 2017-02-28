#include <vector>
#include "population.hpp"
#include "individual.hpp"
using namespace std;

void geneticAlgo(Population&, Individual*, int, int loozerFactor=20);
bool compare(Individual* individual1, Individual* individual2);
