#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED
#include "individual.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Path : public Individual {
private:
    vector<int> _path;
    static std::vector<std::vector<float> > _graph;
public:
    ~Path();
    Path(int, bool);
    void set_graph(vector<vector<float> >);
    void crossOver(Individual*, Individual*);
    void crossOver2(Individual*, Individual*);
    void mutation();
    void mutation_locale(int);
    void mutation_locale2(int nb_ite);
    void evaluate();
    vector<int> getPath();
    friend ostream& operator<<(ostream&, Path);

};

#endif // PATH_HPP_INCLUDED
