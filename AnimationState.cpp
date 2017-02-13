#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <unistd.h>

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
    std::cout << "Before clear" << '\n';
    m_population.clear();
    std::cout << "After clear" << '\n';
    for (int i = 0; i < (int) population->size(); i++) {
        Path* path = dynamic_cast<Path*>((*population)[i]);
        m_population.push_back(new Path(*path));
    }
    std::cout << "After push_back" << '\n';
}

void AnimationState::draw() {
    AbstractState::draw();

    std::vector<int> path = dynamic_cast<Path*>(m_population[0])->getPath();
    for (int i = 0; i < (int) path.size(); i++)
        std::cout << path[i];
    std::cout << "" << '\n';
    
    for (int i = 0; i < (int) path.size() - 1; i++) {
        drawEdge(m_listPoints[path[i]], m_listPoints[path[i+1]]);
    }
    drawEdge(m_listPoints[path[(int) path.size() - 1]], m_listPoints[path[0]]);
    std::cout << "\n";
}

void AnimationState::update() {
    std::cout << "Update" << '\n';

    std::cout << "Before genetic algo : ";

    usleep(500000);
    geneticAlgo(m_population, 1, m_nbLoosers);

    std::cout << "After genetic algo : ";
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
