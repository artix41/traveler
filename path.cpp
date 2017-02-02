#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "path.hpp"
using namespace std;


void Path::set_graph(vector<vector<float> > graph){
  _graph = graph;
}

Path::Path(int pathLen, bool randomGen=false){
    if(randomGen){
        for(int i = 0 ; i<pathLen ; i++){
            _path.push_back(i);
        }
        for(int i = 0 ; i<pathLen ; i++){
            int j = rand()%(_path.size()-i) + i;
            iter_swap(_path.begin()+i, _path.begin()+j);
        }
    }
    else{
        for(int i(0) ; i<pathLen ; i++){
            _path[i] = -1;
        }
    }
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
    vector<bool> assigned(false,path1->_path.size());
    vector<int> notAssigned;
    for(unsigned int i = 0 ; i<path1->_path.size(); i++){
        if (not is_in(_path, path1->_path[i])){
            if (not is_in(_path, path2->_path[i])){
                int r = rand()%1;
                _path[i] = r*path1->_path[i] + (1-r)*path2->_path[i];
            }
            else{
                _path[i] = path1->_path[i];
            }
        }
        else{
            if (not is_in(_path, path2->_path[i])){
                _path[i] = path2->_path[i];
            }
        }
    }

    for(unsigned int i = 0 ; i<path1->_path.size(); i++){
        if (_path[i]!=-1)
        {
          assigned[_path[i]] = true;
        }
    }

    for(unsigned int i = 0 ; i<path1->_path.size(); i++){
        if (not assigned[i])
        {
            notAssigned.push_back(i);
        }
    }
    for(unsigned int i = 0; i<notAssigned.size(); i++){
      int r = rand()%notAssigned.size();
      iter_swap(notAssigned.begin()+i, notAssigned.begin()+r);
    }
    for (unsigned int i = 0; i < path1->_path.size(); i++) {
      if (_path[i]==-1){
        _path[i] = notAssigned[notAssigned.size()-1];
        notAssigned.pop_back();
      }
    }
}

void Path::mutation(){
  int r1 = rand()%_path.size();
  int r2 = rand()%_path.size();
  iter_swap(_path.begin()+r1, _path.begin()+r2);
}

void Path::mutation2(){
  int a = rand()%_path.size();
  int b = rand()%_path.size();
  int r1 = min(a,b);
  int r2 = max(a,b);
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


template<class T>
bool is_in(const std::vector<T>& list, T x){
    for(unsigned int j = 0; j<list.size(); j++){
        if(x == list[j]){
            return(true);
        }
    }
    return(false);
}
