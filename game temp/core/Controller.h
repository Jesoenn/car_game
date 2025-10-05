//
// Created by jakub on 30.09.2025.
//

#ifndef INPUT_H
#define INPUT_H


#include <iostream>
#include <optional>
#include "SFML/Window/Event.hpp"
#include "../entities/Car.h"
#include "CarController.h"

class Controller {
public:
    void update(sf::Time dt, Car& car);

private:
    CarController carController;
};



#endif //INPUT_H
