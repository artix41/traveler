#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include "population.hpp"
#include "individual.hpp"
using namespace std;

Population::~Population(){
  this->clear();
}

Individual* Population::choose(int n){
  return at(rand()%n);
}

Individual* Population::choose2(int n, int p){
  int r = rand() %((n+1)*n/2+n*p);
  int index = floor((sqrt(pow(1+2*p, 2)+8*r)-(1+2*p))/2);
  return at(n-1-index);
}

void Population::selection(int nbShuffled){
  for(unsigned int i = size()-nbShuffled; i<size(); i++){
    int r = rand()%(size()-i)+i;
    iter_swap(begin()+i, begin()+r);
  }
}


void Population::selection2(int nbSelected, int p){
  vector<int> weight;

  for(unsigned int i=0;i<size();i++){
    weight.push_back(size()-i);
  }
  int sum = (size()-5)*(size()-4)/2+(size()-5)*p;
  for(int i=5;i<nbSelected+5;i++){
    int r = rand() %sum;
    int s = 0;
    int j = i-1;
    while (s<=r){
      j++;
      s += weight[j]+p;
    }
    iter_swap(begin()+i, begin()+j);
    iter_swap(weight.begin()+i, weight.begin()+j);
    sum -= weight[i] + p;
  }
}
