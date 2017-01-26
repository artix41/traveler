#ifndef PATH_HPP_INCLUDED
#define PATH_HPP_INCLUDED
#include "individual.hpp"

class Path : public Individual {
private:
    int* path;
public:
    Path();
    friend Path* cross_over(Path path1, Path path2) const;
    Path mutation();
    void evaluate(const & std::vector<std::vector<float>> M);

};


#endif // PATH_HPP_INCLUDED
