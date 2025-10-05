//
// Created by jakub on 30.09.2025.
//

#include "Controller.h"

void Controller::update(sf::Time dt, Car& car) {
    carController.update(dt, car);
}
