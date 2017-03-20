#ifndef CREATE_GRAPH_STATE_H
#define CREATE_GRAPH_STATE_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "AbstractState.hpp"

class Display;

class CreateGraphState : public AbstractState {
public:
    CreateGraphState(Display* display, int nbrPointsInit);
    void draw();
    void update();
    void handleEvents(sf::Event& evt);
    void createRandomPoints(int n);
    void createUlyssePoints();
private:
    int m_nbrPointsInit;
};

#endif
