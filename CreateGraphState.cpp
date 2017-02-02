#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Display.hpp"
#include "CreateGraphState.hpp"
#include "AbstractState.hpp"
#include "AnimationState.hpp"

CreateGraphState::CreateGraphState(Display* display):
    AbstractState(display)
{
    m_textureBackground.loadFromFile("maps/game_of_throne.png");
    m_background.setTexture(m_textureBackground);
    m_radiusPoint = 10;
    m_colorPoint = sf::Color::Red;
}

void CreateGraphState::draw() {
    AbstractState::draw();
}

void CreateGraphState::handleEvents(sf::Event &evt) {
    switch (evt.type)
    {
        case sf::Event::MouseButtonPressed:
        {
            auto position = m_renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_renderWindow));
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
                case sf::Keyboard::Return: {
                    std::cout << "Démarre l'animation" << '\n';
                    AnimationState* animationState = new AnimationState(m_display);
                    m_display->push(animationState);
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
