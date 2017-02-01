#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED
#include "individual.hpp"

class Path : public Individual {
private:
    int* _path;
    int _pathLen;
    static std::vector<std::vector<float>> _graph;
public:
    Path(int pathLen);
    friend Path* crossOver(Path path1, Path path2) const;
    Path mutation();
    void evaluate();

};


#endif // PATH_HPP_INCLUDED
