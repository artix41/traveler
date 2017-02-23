#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "path_glouton.hpp"
using namespace std;

Path_glouton::~Path_glouton(){}

void Path_glouton::set_graph(vector<vector<float> > graph){
  _graph = graph;
}

Path_glouton::Path_glouton(int pathLen, bool randomGen=false){
    if(randomGen){
        for(int i = 0 ; i<pathLen-1 ; i++){
            _path.push_back(rand()%(pathLen-1-i));
        }
    }
    else{
        for(int i(0) ; i<pathLen-1 ; i++){
            _path.push_back(0);
        }
    }
}

ostream & operator<<(ostream& out, Path_glouton path){
  out<<"["<< path._path[0];
  for(unsigned int i = 1; i< path._path.size();i++){
    out<<", "<< path._path[i];
  }
  out<<"]";
  out<<", fitness = "<<path._fitness;
  return out;
}

void Path_glouton::crossOver(Individual* path1a, Individual* path2a){
    Path_glouton* path1 = dynamic_cast<Path_glouton*>(path1a);
    Path_glouton* path2 = dynamic_cast<Path_glouton*>(path2a);

    for(unsigned int i = 1 ; i<_path.size(); i++){
      int r = rand()%2;
      _path[i] = path1->_path[i]*r + path2->_path[i]*(1-r);
    }
}

void Path_glouton::crossOver2(Individual* path1a, Individual* path2a){
    Path_glouton* path1 = dynamic_cast<Path_glouton*>(path1a);
    Path_glouton* path2 = dynamic_cast<Path_glouton*>(path2a);

    int r1 = rand()%_path.size();
    int r2 = rand()%(_path.size()-r1)+r1;

    for(unsigned int i = 1 ; i<_path.size(); i++){
        if (i<r1 or i>r2){
            _path[i] = path1->_path[i];
          }
        else{
            _path[i] = path2->_path[i];
        }
    }

}

void Path_glouton::mutation2(){}

void Path_glouton::mutation(){
  int r1 = rand()%_path.size();
  _path[r1] = rand()%(_path.size()-r1);
}

void Path_glouton::evaluate(){
    _fitness = 0;
    current = 0;
    vector<int> restant;
    for(int i = 1; i<_path.size()+1; i++){
      restant.push_back(i);
    }
    for(int i = 0; i<_path.size()-1; i++){
      sort(restant.begin(),restant.end(),*this);
      _fitness+=_graph[current][restant[_path[i]]];
      current = restant[_path[i]];
      restant[_path[i]] = restant[restant.size()-1];
      restant.pop_back();
    }
    _fitness+=_graph[current][0];
}

bool Path_glouton::operator()(int a, int b){return _graph[current][a]<_graph[current][b];}
