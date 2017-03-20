#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#include "Display.hpp"
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
#include "path.hpp"

int main()
{
    srand(42);
    Display display(100);
    display.run();
    return 0;
}
