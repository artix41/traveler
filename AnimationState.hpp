#ifndef ANIMATION_STATE_H
#define ANIMATION_STATE_H

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Display.hpp"
#include "AbstractState.hpp"
#include "population.hpp"

class AnimationState : public AbstractState {
public:
    AnimationState(Display* display);
    void draw();
    void update();
    void handleEvents(sf::Event &evt);
    void drawEdge(sf::Vector2f point1, sf::Vector2f point2);
    void setPopulation(Population* population);

private:
    Population m_population;
    std::vector<std::vector<float> > m_graph;

    int m_widthEdge;
    sf::Color m_colorEdge;
    int m_nbLoosers;
    int m_sizePopulation;

    void createGraph();
    void initPopulation();
};

#endif
