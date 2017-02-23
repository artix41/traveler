#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED
#include "individual.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Path_glouton : public Individual {
private:
    vector<int> _path;
    int current;
    static std::vector<std::vector<float> > _graph;
public:
    ~Path_glouton();
    Path_glouton(int, bool);
    void set_graph(vector<vector<float> >);
    void crossOver(Individual*, Individual*);
    void crossOver2(Individual*, Individual*);
    void mutation();
    void mutation2();
    void evaluate();
    bool operator()(int,int);
    friend ostream& operator<<(ostream&, Path_glouton);

};

#endif // PATH_HPP_INCLUDED
