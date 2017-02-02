#include <vector>
#include "population.hpp"
#include "individual.hpp"
using namespace std;

Individual* geneticAlgo(Population&, int, int nbLoozer=10);
bool compare(Individual* individual1, Individual* individual2);
