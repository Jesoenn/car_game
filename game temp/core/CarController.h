//
// Created by jakub on 30.09.2025.
//

#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H


#include "../entities/Car.h"
#include "SFML/System/Time.hpp"

class CarController {
public:
    void update(sf::Time dt, Car& car);
};



#endif //CARCONTROLLER_H
