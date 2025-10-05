//
// Created by jakub on 30.09.2025.
//

#ifndef CAR_H
#define CAR_H
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
#include "../enums/TurnTypes.h"


class Car {
public:
    Car(sf::Vector2f size, float acceleration, float maxSpeed, sf::Angle rotation,
        float brakeForce, float engineBrakingForce);

    //Actions
    void accelerate(sf::Time dt);
    void decelerate(sf::Time dt);
    void reverse(sf::Time dt);
    void turn(TurnTypes turn, sf::Time dt);

    void updatePos(sf::Time dt);

    //Setters
    void setPosition(sf::Vector2f position);
    void setSlow(float slow);

    //Getters
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::Angle getAngle() const;
    float getSlowModifier() const;

private:
    const sf::Vector2f size;
    const float acceleration, maxSpeed, brakeForce, engineBrakingForce;
    const sf::Angle rotation;

    sf::Angle angle;
    sf::Vector2f position;
    float velocity, slowModifier;
};



#endif //CAR_H
