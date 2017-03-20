#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class AbstractState;

struct VideoSettings
{
    sf::Int32 windowStyle;
    sf::VideoMode videoMode;
    std::vector<sf::VideoMode> availableVideoModes;

    VideoSettings():
        windowStyle   (sf::Style::Close | sf::Style::Resize),
        videoMode       (1024, 600){}

};

class Display {
public:
    Display(int nbrPointsInit);
    void run();
    void push(AbstractState* state);
    void pop();
    AbstractState* back();
    sf::RenderWindow& getRenderWindow();

private:
    VideoSettings m_videoSettings;
    std::string m_windowTitle;
    sf::RenderWindow m_renderWindow;
    std::vector<AbstractState*> m_stateStack;
};

#endif
