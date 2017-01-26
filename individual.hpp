#ifndef INDIVIDUAL_HPP_INCLUDED
#define INDIVIDUAL_HPP_INCLUDED

class Individual {
protected:
    float fitness;
public:
    virtual friend Individual* cross_over(Individual individual1, Individual individual2)=0;
    virtual Individual mutation()=0;
    friend bool operator<(Individual individual1, Individual individual2);
};


#endif // INDIVIDUAL_HPP_INCLUDED
