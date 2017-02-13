#include <cstdlib>
#include <vector>
#include <cmath>
#include "population.hpp"
#include "individual.hpp"
using namespace std;

Population::~Population(){
  this->clear();
}

Individual* Population::choose(int n){
  return at(rand() %n);
}

Individual* Population::choose2(int n, int p){
  int r = rand() %((n+1)*n/2+n*p);
  int index = floor((sqrt(pow(1+2*p, 2)+8*r)-(1+2*p))/2);
  return at(n-1-index);
}

void Population::selection(int nbSelected){}

void Population::selection2(int nbSelected, int p){
  vector<int> order(size());

  for(unsigned int i=0;i<size();i++){
    order[i] = i;
  }
  int sum = (size()+1)*size()/2+size()*p;

  for(int i=0;i<nbSelected;i++){
    int r = rand() %sum + 1;
    int s = 0;
    int j = i-1;
    while (s<r){
      j++;
      s += order[j]+p;
    }
    iter_swap(begin()+i, begin()+j);
    iter_swap(order.begin()+i, order.begin()+j);
    sum -= order[i] + p;
  }
}
