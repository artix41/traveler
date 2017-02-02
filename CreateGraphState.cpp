#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "CreateGraphState.hpp"
#include "AbstractState.hpp"

CreateGraphState::CreateGraphState(sf::RenderWindow& renderWindow):
    AbstractState(renderWindow)
{
    m_textureBackground.loadFromFile("maps/game_of_throne.png");
    m_background.setTexture(m_textureBackground);
    addPoint(sf::Vector2f(0,0));
    addPoint(sf::Vector2f(500,300));

    m_radiusPoint = 10;
    m_colorPoint = sf::Color::Red;
}

void CreateGraphState::addPoint(sf::Vector2f point) {
    m_listPoints.push_back(point);
}

void CreateGraphState::removePoint(int index) {
    m_listPoints.erase(m_listPoints.begin() + index);
}

void CreateGraphState::draw() {
    for (int i=0; i < (int) m_listPoints.size(); i++) {
        sf::CircleShape circle;
        circle.setRadius(m_radiusPoint);
        circle.setFillColor(m_colorPoint);
        circle.setPosition(m_listPoints[i].x, m_listPoints[i].y);
        circle.setOrigin(sf::Vector2f(circle.getGlobalBounds().width/2, circle.getGlobalBounds().height/2));
        m_renderWindow.draw(circle);
    }
}

void CreateGraphState::handleEvents(sf::Event &evt) {
    switch (evt.type)
    {
        case sf::Event::MouseButtonPressed:
        {
            auto position = m_renderWindow.mapPixelToCoords(sf::Mouse::getPosition(m_renderWindow));
            switch (evt.mouseButton.button)
            {
                case sf::Mouse::Left:
                {
                    bool hasRemoved = false;
                    for (int iPoint = 0; iPoint < (int) m_listPoints.size(); iPoint++) {
                        if (pow(m_listPoints[iPoint].x - position.x, 2) + pow(m_listPoints[iPoint].y - position.y, 2) <= pow(m_radiusPoint,2)) {
                            removePoint(iPoint);
                            hasRemoved = true;
                        }
                    }
                    if (!hasRemoved)
                        addPoint((sf::Vector2f) position);
                    break;
                }
                default: break;
            }
        break;
        }
        case sf::Event::KeyPressed:
        {
            switch (evt.key.code)
            {
                case sf::Keyboard::Left:
                    // Change background to the left
                    break;
                case sf::Keyboard::Right:
                    // Change background to the right
                    break;
                case sf::Keyboard::E:
                    m_listPoints.clear();
                    break;
                default:
                    break;
            }
            break;
        }
        default: break;
    }
}
