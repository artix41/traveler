#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "path.hpp"
using namespace std;

std::vector<std::vector<float> > Path::_graph;
Path::~Path(){}

void Path::set_graph(vector<vector<float> > graph){
  _graph = graph;
}

Path::Path(int pathLen, bool randomGen=false){
    if(randomGen){
        for(int i = 0 ; i<pathLen ; i++){
            _path.push_back(i);
        }
        for(int i = 1 ; i<pathLen ; i++){
            int j = rand()%(_path.size()-i) + i;
            iter_swap(_path.begin()+i, _path.begin()+j);
        }
    }
    else{
        for(int i(0) ; i<pathLen ; i++){
            _path.push_back(-1);
        }
        _path[0] = 0;
    }
}

vector<int> Path::getPath() {
    return _path;
}

ostream & operator<<(ostream& out, Path path){
  out<<"["<< path._path[0];
  for(unsigned int i = 1; i< path._path.size();i++){
    out<<", "<< path._path[i];
  }
  out<<"]";
  out<<", fitness = "<<path._fitness;
  return out;
}

void Path::crossOver(Individual* path1a, Individual* path2a){
    Path* path1 = dynamic_cast<Path*>(path1a);
    Path* path2 = dynamic_cast<Path*>(path2a);
    unsigned int len = _path.size();
    vector<bool> assigned(len,false);
    vector<int> notAssigned;

    for(unsigned int i = 1 ; i<len; i++){
      _path[i] = -1;
    }

    for(unsigned int i = 1 ; i<len; i++){
        if (not assigned[path1->_path[i]]){
            if (not assigned[path2->_path[i]]){
                int r = rand()%2;
                if( r==1){
                  _path[i] = path1->_path[i];
                }
                else{
                  _path[i] = path2->_path[i];
                }
            }
            else{
                _path[i] = path1->_path[i];
            }
        }
        else{
            if (not assigned[path2->_path[i]]){
                _path[i] = path2->_path[i];
            }
        }
        if(_path[i]!=-1){
          assigned[_path[i]] = true;
        }
    }


    for(unsigned int i = 1 ; i<len; i++){
        if (not assigned[i]) {
            notAssigned.push_back(i);
        }
    }
    for(unsigned int i = 0; i<notAssigned.size(); i++){
      int r = rand()%(notAssigned.size()-i)+i;
      iter_swap(notAssigned.begin()+i, notAssigned.begin()+r);
    }
    for (unsigned int i = 1; i<len; i++) {
      if (_path[i]==-1){
        _path[i] = notAssigned[notAssigned.size()-1];
        notAssigned.pop_back();
      }
    }
}

void Path::crossOver2(Individual* path1a, Individual* path2a){
    Path* path1 = dynamic_cast<Path*>(path1a);
    Path* path2 = dynamic_cast<Path*>(path2a);
    unsigned int len = _path.size();
    vector<bool> assigned(len,false);
    vector<int> notAssigned;

    for(unsigned int i = 1 ; i<len; i++){
      _path[i] = -1;
    }
    int r1 = rand()%_path.size();
    int r2 = rand()%(_path.size()-r1)+r1;
    int gene;

    for(unsigned int i = 1 ; i<len; i++){
        if ((int) i < r1 or (int) i > r2){
            gene = path1->_path[i];
          }
        else{
            gene = path2->_path[i];
        }
        if (not assigned[gene]){
                _path[i] = gene;
                assigned[gene] = true;
        }
    }

    for(unsigned int i = 1 ; i<len; i++){
        if (not assigned[i]) {
            notAssigned.push_back(i);
        }
    }
    for(unsigned int i = 0; i<notAssigned.size(); i++){
      int r = rand()%(notAssigned.size()-i)+i;
      iter_swap(notAssigned.begin()+i, notAssigned.begin()+r);
    }
    for (unsigned int i = 1; i<len; i++) {
      if (_path[i]==-1){
        _path[i] = notAssigned[notAssigned.size()-1];
        notAssigned.pop_back();
      }
    }
}

void Path::mutation2(){
  int r1 = rand()%(_path.size()-1)+1;
  int r2 = rand()%(_path.size()-1)+1;
  iter_swap(_path.begin()+r1, _path.begin()+r2);
}

void Path::mutation(){
  int r1 = rand()%(_path.size()-1)+1;
  int r2 = rand()%(_path.size()-r1)+r1;
  for(int i = 0;i<(r2-r1+1)/2; i++){
    iter_swap(_path.begin()+r1+i, _path.begin()+r2-i);
  }
}

void Path::evaluate(){
    _fitness = _graph[_path[_path.size()-1]][_path[0]];
    for(unsigned int i = 0; i<_path.size()-1 ; i++){
        _fitness += _graph[_path[i]][_path[i+1]];
    }
}

void Path::shuffle(){
  for(unsigned int i = 1 ; i<_path.size() ; i++){
      int j = rand()%(_path.size()-i) + i;
      iter_swap(_path.begin()+i, _path.begin()+j);
  }
}
