#ifndef CREATE_GRAPH_STATE_H
#define CREATE_GRAPH_STATE_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "DisplayState.hpp"

class CreateGraphState : public DisplayState {
public:
    CreateGraphState(sf::RenderWindow& renderWindow);

    void update();
    void draw();
    void handleEvents(sf::Event& evt);
    void addPoint(sf::Vector2f point);
    void removePoint(int index);
private:
    std::vector<sf::Vector2f> m_listPoints;
    int m_radiusPoint;
    sf::Color m_colorPoint;
};

#endif
