//
// Created by jakub on 30.09.2025.
//

#include "Input.h"

void Input::update(sf::Time dt, Car& car) {
    carController.update(dt, car);
}
