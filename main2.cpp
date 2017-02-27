#include <iostream>
#include <vector>
#include <cmath>
#include "algo_genetique.hpp"
#include "population.hpp"
#include "individual.hpp"
#include "path.hpp"

using namespace std;

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
    Population population;
    vector<float> x;
    vector<float> y;
    for (int i = 0; i<1000; i++){
      x.push_back(rand()%100);
      y.push_back(rand()%100);
    }
    // vector<float> x={38.24,39.57,40.56,36.26,33.48,37.56,38.42,37.52,41.23,41.17,36.08,38.47,38.15,37.51,35.49,39.36,38.09,36.09,40.44,40.33,40.37,37.57};
    // vector<float> y={20.42,26.15,25.32,23.12,10.54,12.19,13.11,20.44,9.10,13.05,-5.21,15.13,15.35,15.17,14.32,19.56,24.36,23.00,13.57,14.15,14.23,22.56};
    // x = {0,0,1,1,2,2,3,3,4,4,5,5};
    // y = {0,1,0,1,0,1,0,1,0,1,0,1};
    vector<vector<float> > graph = createGraph(x,y);
    srand(time(NULL));

    for (int i = 0; i<1; i++){
      population.clear();
      for (unsigned int i=0; i<500; i++){
        population.push_back(new Path(graph.size(),true));
      }
      Path path(graph.size(),true);
      path.set_graph(graph);
      geneticAlgo(population, 100000);
      Path* solution = dynamic_cast<Path*>(population[0]);
      std::cout << (*solution) << '\n';
    }
    return 0;
}
