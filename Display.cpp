#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <unistd.h>

#include "Display.hpp"
#include "AbstractState.hpp"
#include "CreateGraphState.hpp"
#include "AnimationState.hpp"

Display::Display():
    m_videoSettings(),
    m_windowTitle("Genetic Travelling Salesman"),
    m_renderWindow (m_videoSettings.videoMode, m_windowTitle, m_videoSettings.windowStyle)
{
    CreateGraphState* createGraphState = new CreateGraphState(this);
    m_stateStack.push_back(createGraphState);
}

void Display::push(AbstractState* state) {
    m_stateStack.push_back(state);
}

void Display::pop() {
    if (m_stateStack.size() > 1) {
        m_stateStack.pop_back();
    }
}

AbstractState* Display::back() {
    return m_stateStack.back();
}

sf::RenderWindow& Display::getRenderWindow() {
    return m_renderWindow;
}

void Display::run() {
    std::cout << "Démarrage de l'interface" << std::endl;
    sf::Texture textureBackground;
    if (!textureBackground.loadFromFile("maps/ensta.jpg")) {
        std::cout << "Problem when loading the background" << std::endl;
    }
    sf::Sprite background;
    background.setTexture(m_stateStack.back()->getTexture());
    background.setScale(
    m_renderWindow.getSize().x / background.getLocalBounds().width,
    m_renderWindow.getSize().y / background.getLocalBounds().height);

    while (m_renderWindow.isOpen()) {
        sf::Event event;

        while (m_renderWindow.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_renderWindow.close();
                    break;
                default:
                    break;
            }
            m_stateStack.back()->handleEvents(event);
        }
        m_renderWindow.clear();
        m_renderWindow.draw(background);

        m_stateStack.back()->draw();
        m_stateStack.back()->update();

        //m_renderWindow.draw(background);
        m_renderWindow.display();
    }
}
