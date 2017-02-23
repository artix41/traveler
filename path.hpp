#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED
#include "individual.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Path : public Individual {
public:
    vector<int> _path;
    static std::vector<std::vector<float> > _graph;
public:
    ~Path();
    Path(int, bool);
    void set_graph(vector<vector<float> >);
    void crossOver(Individual*, Individual*);
    void crossOver2(Individual*, Individual*);
    void mutation();
    void mutation2();
    void evaluate();
    void shuffle();
    friend ostream& operator<<(ostream&, Path);

};

#endif // PATH_HPP_INCLUDED
