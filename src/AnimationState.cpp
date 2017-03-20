#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <unistd.h>
#include <string>
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "AnimationState.hpp"
#include "CreateGraphState.hpp"
#include "population.hpp"
#include "path.hpp"
#include "algo_genetique.hpp"

AnimationState::AnimationState(Display* display):
    AbstractState(display)
{
    m_textureBackground = display->back()->getTexture();
    m_listPoints = display->back()->getListPoints();
    m_radiusPoint = display->back()->getRadiusPoint();
    m_colorPoint = display->back()->getColorPoint();
    std::cout << m_listPoints.size() << '\n';

    m_generation = 1;

    m_widthEdge = 5;
    m_colorEdge = m_colorPoint;

    m_sizePopulation = 1000;
    m_nbLoosers = 100;

    createGraph();
    initPopulation();
}

float distance(sf::Vector2f p1 , sf::Vector2f p2) {
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

void AnimationState::createGraph() {
    for (int i = 0; i < (int) m_listPoints.size(); i++) {
        std::vector<float> line;
        m_graph.push_back(line);
        for (int j = 0; j < (int) m_listPoints.size(); j++) {
            m_graph[i].push_back(distance(m_listPoints[i], m_listPoints[j]));
        }
    }
}

void AnimationState::initPopulation() {
    Path path(m_graph.size(),true);
    path.set_graph(m_graph);

    for (int i=0; i < m_sizePopulation; i++) {
        m_population.push_back(new Path(m_graph.size(),true));
        m_population.front()->evaluate();
    }
}

void AnimationState::drawEdge(sf::Vector2f point1, sf::Vector2f point2) {
    sf::Vector2f direction = point2 - point1;
    sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
    sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);
    sf::Vector2f offset = (m_widthEdge/2.f)*unitPerpendicular;

    sf::Vertex vertices[4];
    vertices[0].position = point1 + offset;
    vertices[1].position = point2 + offset;
    vertices[2].position = point2 - offset;
    vertices[3].position = point1 - offset;

    for (int i=0; i<4; ++i)
        vertices[i].color = m_colorEdge;

    m_renderWindow->draw(vertices,4,sf::Quads);
}

void AnimationState::setPopulation(Population *population) {
    m_population.clear();
    for (int i = 0; i < (int) population->size(); i++) {
        Path* path = dynamic_cast<Path*>((*population)[i]);
        m_population.push_back(new Path(*path));
    }
}

void AnimationState::draw() {
    AbstractState::draw();

    // Draw Edges
    std::vector<int> path = dynamic_cast<Path*>(m_population[0])->getPath();
    for (int i = 0; i < (int) path.size() - 1; i++) {
        drawEdge(m_listPoints[path[i]], m_listPoints[path[i+1]]);
    }
    drawEdge(m_listPoints[path[(int) path.size() - 1]], m_listPoints[path[0]]);

    // Draw text (generation, distance)
    float distance = m_population[0]->get_fitness();
    std::cout << "Distance : " << distance << '\n';

    stringstream streamDistance;
    streamDistance << fixed << setprecision(2) << distance;
    string strDistance = "Distance : " + streamDistance.str();
    string strGeneration = "Generation : " + std::to_string(m_generation);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSerif.ttf")) {
        std::cout << "Can't load the font" << '\n';
    }

    sf::Text textDistance;
    textDistance.setFont(font);
    textDistance.setCharacterSize(20);
    textDistance.setStyle(sf::Text::Bold);
    textDistance.setColor(sf::Color::Black);
    textDistance.setString(strDistance);
    textDistance.setOrigin(textDistance.getGlobalBounds().width, 0);
    textDistance.setPosition(sf::Vector2f(m_renderWindow->getSize().x  - 10, 0));

    sf::Text textGeneration = sf::Text(textDistance);
    textGeneration.setString(strGeneration);
    textGeneration.setOrigin(textGeneration.getGlobalBounds().width, 0);
    textGeneration.setPosition(sf::Vector2f(m_renderWindow->getSize().x  - 10, textDistance.getGlobalBounds().height + 10));


    m_renderWindow->draw(textDistance);
    m_renderWindow->draw(textGeneration);

    std::cout << "\n";
}

void AnimationState::update() {
    int n = 1;
    m_generation+=n;
    Path path(m_listPoints.size(), true);
    std::cout << "Generation : " << m_generation << '\n';
    usleep(1);
    geneticAlgo(m_population, &path, n, m_nbLoosers);
}

void AnimationState::handleEvents(sf::Event &evt) {
    switch (evt.type) {
        case sf::Event::KeyPressed: {
            switch (evt.key.code) {
                case sf::Keyboard::Return: {
                    m_display->pop();
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
