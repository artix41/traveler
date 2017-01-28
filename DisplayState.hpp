#ifndef DISPLAY_STATE_H
#define DISPLAY_STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class DisplayState {
protected:
    sf::RenderWindow& m_renderWindow;
    sf::Texture m_textureBackground;
    sf::Sprite m_background;

public:
    DisplayState(sf::RenderWindow& renderWindow);
    sf::Sprite& getBackground();
    sf::Texture& getTexture();

    virtual void draw() = 0;
    virtual void handleEvents(sf::Event& evt) = 0;
    //virtual void update() = 0;
};

#endif
