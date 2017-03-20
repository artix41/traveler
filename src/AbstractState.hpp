#ifndef DISPLAY_STATE_H
#define DISPLAY_STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Display;

class AbstractState {
public:
    AbstractState(Display* display);

    virtual void draw()=0;
    virtual void update()=0;
    virtual void handleEvents(sf::Event& evt)=0;

    sf::Sprite& getBackground();
    sf::Texture& getTexture();
    void addPoint(sf::Vector2f point);
    void removePoint(int index);
    std::vector<sf::Vector2f> getListPoints();
    int getRadiusPoint();
    sf::Color getColorPoint();

protected:
    Display* m_display;
    sf::RenderWindow *m_renderWindow;
    sf::Texture m_textureBackground;
    sf::Sprite m_background;

    std::vector<sf::Vector2f> m_listPoints;
    int m_radiusPoint;
    sf::Color m_colorPoint;
};

#endif
