#ifndef ANIMATION_STATE_H
#define ANIMATION_STATE_H

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Display.hpp"
#include "AbstractState.hpp"

class AnimationState : public AbstractState {
public:
    AnimationState(Display* display);
    void draw();
    void handleEvents(sf::Event &evt);
    void addEdge(sf::Vector2f point1, sf::Vector2f point2);
};

#endif
