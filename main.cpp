#include <iostream>
#include <vector>
#include <cmath>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
#include "path.hpp"

using namespace std;
vector<vector<float> > Path::_graph;

float distance(float x1, float y1, float x2, float y2){return sqrt(pow(x1-x2,2)+pow(y1-y2,2));}

vector<vector<float> > createGraph(const vector<float>& x, const vector<float>& y){
  vector<vector<float> > graph;
  for(unsigned int i = 0; i<x.size(); i++){
    vector<float> line;
    graph.push_back(line);
    for(unsigned int j = 0; j<y.size(); j++){
      graph[i].push_back(distance(x[i],y[i],x[j],y[j]));
    }
  }
  return graph;
}

int main()
{
    srand(time(NULL));
    Population population;
    vector<float> x={0,2,3,1,4,4,1,4,0,2};
    vector<float> y={0,0,1,1,0,1,2,2,3,3};
    vector<vector<float> > graph = createGraph(x,y);

    for (unsigned int i=0; i<100; i++){
      population.push_back(new Path(graph.size(),true));
    }
    Path path(graph.size(),true);
    path.set_graph(graph);
    geneticAlgo(population, 1000);
    Path* solution = dynamic_cast<Path*>(population[0]);
    std::cout << *solution << '\n';
    return 0;
}
