#include <iostream>
#include <SFML/Graphics.hpp>

#include "DisplayState.hpp"

DisplayState::DisplayState(sf::RenderWindow& renderWindow):
    m_renderWindow(renderWindow),
    m_textureBackground(),
    m_background()
{}

sf::Sprite& DisplayState::getBackground() {
    return m_background;
};

sf::Texture& DisplayState::getTexture() {
    return m_textureBackground;
};
