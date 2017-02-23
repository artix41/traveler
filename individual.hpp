#ifndef INDIVIDUAL_HPP_INCLUDED
#define INDIVIDUAL_HPP_INCLUDED

class Individual {
protected:
    float _fitness;
public:
    virtual void mutation()=0;
    virtual void mutation2()=0;
    virtual ~Individual();
    virtual void evaluate()=0;
    float get_fitness();
    virtual void shuffle()=0;
    virtual void crossOver(Individual *, Individual *)=0;
    virtual void crossOver2(Individual *, Individual *)=0;
    friend bool operator<(Individual const &, Individual const &);
};

#endif // INDIVIDUAL_HPP_INCLUDED
