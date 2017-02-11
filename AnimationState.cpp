#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "AnimationState.hpp"
#include "CreateGraphState.hpp"

AnimationState::AnimationState(Display* display):
    AbstractState(display)
{
    m_textureBackground = display->back()->getTexture();
    m_listPoints = display->back()->getListPoints();
    m_radiusPoint = display->back()->getRadiusPoint();
    m_colorPoint = display->back()->getColorPoint();
}

void AnimationState::draw() {
    AbstractState::draw();
}

void AnimationState::handleEvents(sf::Event &evt) {
    switch (evt.type) {
        case sf::Event::KeyPressed: {
            switch (evt.key.code) {
                case sf::Keyboard::Return: {
                    m_display->pop();
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default: break;
    }
}
