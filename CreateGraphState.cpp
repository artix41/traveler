#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

#include "Display.hpp"
#include "CreateGraphState.hpp"
#include "AbstractState.hpp"
#include "AnimationState.hpp"

CreateGraphState::CreateGraphState(Display* display, int nbrPointsInit):
    AbstractState(display)
{
    m_textureBackground.loadFromFile("maps/game_of_throne.png");
    m_background.setTexture(m_textureBackground);
    m_radiusPoint = 5;
    m_colorPoint = sf::Color(244, 67, 54, 200);
    m_nbrPointsInit = nbrPointsInit;
}

void CreateGraphState::draw() {
    AbstractState::draw();
}

void CreateGraphState::update() {

}

void CreateGraphState::createRandomPoints(int n) {
    for (int i = 0; i < n; i++) {
        int randWidth = (rand() % m_renderWindow->getSize().x);
        int randHeight = (rand() % m_renderWindow->getSize().y);
        addPoint(sf::Vector2f(randWidth, randHeight));
    }
}

void CreateGraphState::createUlyssePoints() {
    vector<float> x = {38.24,39.57,40.56,36.26,33.48,37.56,38.42,37.52,41.23,41.17,36.08,38.47,38.15,37.51,35.49,39.36,38.09,36.09,40.44,40.33,40.37,37.57};
    vector<float> y = {20.42,26.15,25.32,23.12,10.54,12.19,13.11,20.44,9.10,13.05,-5.21,15.13,15.35,15.17,14.32,19.56,24.36,23.00,13.57,14.15,14.23,22.56};

    for (size_t i = 0; i < x.size(); i++) {
        addPoint(sf::Vector2f(x[i]*20, y[i]*20 + 120));
    }
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
                case sf::Keyboard::R:
                    createRandomPoints(m_nbrPointsInit);
                    break;
                case sf::Keyboard::U:
                    createUlyssePoints();
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
