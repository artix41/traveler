#include <iostream>
#include <vector>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
#include "path.hpp"

using namespace std;
vector<vector<float> > Path::_graph;

int main()
{
    Population population;
    vector<vector<float> > graph;
    vector<float> line;
    graph.push_back(line);
    graph[0].push_back(1);
    graph[0].push_back(1);
    graph.push_back(line);
    graph[1].push_back(1);
    graph[1].push_back(1);
    for (unsigned int i=0; i<100; i++){
      Path path(2,true);
      population.push_back(&path);
    }
    Path path(2,true);
    path.set_graph(graph);
    for(unsigned int i = 0; i<population.size();i++){
      std::cout << *((Path*)population[i]) << '\n';
    }
    Individual* sol = geneticAlgo(population, 100);
    Path* sol1 = dynamic_cast<Path*>(sol);
    std::cout << *sol1 << '\n';
    return 0;
}
