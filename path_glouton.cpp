#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "path_glouton.hpp"
using namespace std;

std::vector<std::vector<float> > Path_glouton::_graph;
Path_glouton::~Path_glouton(){}

void Path_glouton::set_graph(vector<vector<float> > graph){
  _graph = graph;
}

Path_glouton::Path_glouton(int pathLen, bool randomGen=false){
    if(randomGen){
        for(int i = 0 ; i<pathLen ; i++){
            _path.push_back(rand()%(pathLen-1));
        }
    }
    else{
        for(int i(0) ; i<pathLen ; i++){
            _path.push_back(0);
        }
    }
}


ostream & operator<<(ostream& out, Path_glouton path){
  path.current = 0;
  out<<"["<< path.current;
  vector<int> restant;
  for(unsigned int i = 1; i<path._path.size(); i++){
    restant.push_back(i);
  }
  for(unsigned int i = 0; i<path._path.size()-1; i++){
    sort(restant.begin(),restant.end(),path);
    int a = path._path[i];
    if (path._path[i]>=restant.size()){
      a = 0;
    }
    path.current = restant[a];
    out<<", "<<path.current;
    restant[a] = restant[restant.size()-1];
    restant.pop_back();
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

    for(int i = 1 ; i<_path.size(); i++){
        if (i<r1 or i>r2){
            _path[i] = path1->_path[i];
          }
        else{
            _path[i] = path2->_path[i];
        }
    }

}

void Path_glouton::mutation2(){
  int r1 = rand()%_path.size();
  _path[r1] += rand()*2-1;
}

void Path_glouton::mutation(){
  int r1 = rand()%_path.size();
  _path[r1] = rand()%(_path.size()-1);
}

void Path_glouton::evaluate(){
    _fitness = 0;
    current = 0;
    vector<int> restant;
    for(unsigned int i = 1; i<_path.size(); i++){
      restant.push_back(i);
    }
    for(unsigned int i = 0; i<_path.size()-1; i++){
      sort(restant.begin(),restant.end(),*this);
      if (_path[i]>=restant.size()){
        _path[i]=0;
      }
      _fitness+=_graph[current][restant[_path[i]]];
      current = restant[_path[i]];
      restant[_path[i]] = restant[restant.size()-1];
      restant.pop_back();
    }
    _fitness+=_graph[current][0];
}

void Path_glouton::shuffle(){
  for(unsigned int i = 0 ; i<_path.size() ; i++){
      _path.push_back(rand()%(_path.size()-1));
  }
}

bool Path_glouton::operator()(int a, int b){return _graph[current][a]<_graph[current][b];}
