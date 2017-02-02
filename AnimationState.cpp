#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "AnimationState.hpp"
#include "CreateGraphState.hpp"

AnimationState::AnimationState(Display* display):
    AbstractState(display)
{}

void AnimationState::draw() {
    AbstractState::draw();
}

void AnimationState::handleEvents(sf::Event &evt) {

}
