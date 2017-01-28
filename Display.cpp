#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Display.hpp"
#include "DisplayState.hpp"
#include "CreateGraphState.hpp"

Display::Display():
    m_videoSettings(),
    m_windowTitle("Genetic Travelling Salesman"),
    m_renderWindow (m_videoSettings.videoMode, m_windowTitle, m_videoSettings.windowStyle)
{
    m_stateStack.push_back(std::make_shared<CreateGraphState>(m_renderWindow));
    std::cout << m_stateStack.empty() << std::endl;
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
        //m_renderWindow.draw(background);
        m_renderWindow.display();
    }
}