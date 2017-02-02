#include <iostream>
#include <SFML/Graphics.hpp>

#include "AbstractState.hpp"
#include "Display.hpp"

AbstractState::AbstractState(Display* display):
    m_display(display),
    m_renderWindow(&display->getRenderWindow()),
    m_textureBackground(),
    m_background()
{}

sf::Sprite& AbstractState::getBackground() {
    return m_background;
};

sf::Texture& AbstractState::getTexture() {
    return m_textureBackground;
};

void AbstractState::draw() {
    for (int i=0; i < (int) m_listPoints.size(); i++) {
        sf::CircleShape circle;
        circle.setRadius(m_radiusPoint);
        circle.setFillColor(m_colorPoint);
        circle.setPosition(m_listPoints[i].x, m_listPoints[i].y);
        circle.setOrigin(sf::Vector2f(circle.getGlobalBounds().width/2, circle.getGlobalBounds().height/2));
        m_renderWindow->draw(circle);
    }
}

void AbstractState::addPoint(sf::Vector2f point) {
    m_listPoints.push_back(point);
}

void AbstractState::removePoint(int index) {
    m_listPoints.erase(m_listPoints.begin() + index);
}
