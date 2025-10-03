//
// Created by jakub on 30.09.2025.
//

#include "CarController.h"
#include "SFML/Window/Keyboard.hpp"

void CarController::update(sf::Time dt, Car &car) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        car.accelerate(dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        car.reverse(dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        car.turn(TurnTypes::LEFT, dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        car.turn(TurnTypes::RIGHT, dt);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        car.decelerate(dt);
    }
    car.updatePos();
}
