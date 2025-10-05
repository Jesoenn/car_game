//
// Created by jakub on 30.09.2025.
//

#include "Car.h"

#include <complex>

Car::Car(sf::Vector2f size, float acceleration, float maxSpeed, sf::Angle rotation, float brakeForce, float engineBrakingForce):
    size(size),
    acceleration(acceleration),
    maxSpeed(maxSpeed),
    brakeForce(brakeForce),
    rotation(rotation),
    angle(sf::radians(0)),
    position({0.f,0.f}),
    velocity(0.f),
    engineBrakingForce(engineBrakingForce),
    slowModifier(1.f){}

//W key
void Car::accelerate(sf::Time dt) {
    if (velocity < 0) {
        velocity += brakeForce * acceleration * dt.asSeconds();
    } else {
        velocity += acceleration * dt.asSeconds();
    }

    if (velocity > maxSpeed) {
        velocity = maxSpeed;
    }
}

//Nothing (Engine braking)
void Car::decelerate(sf::Time dt) {
    float originalVelocity = velocity;

    if (velocity < 0.f) {
        velocity += engineBrakingForce * acceleration * dt.asSeconds();
    } else if (velocity > 0.f) {
        velocity -= engineBrakingForce * acceleration * dt.asSeconds();
    }

    // + to - or - to +  -> car came to a stop
    if (originalVelocity*velocity < 0.f) {
        velocity = 0.f;
    }
}

//S key
void Car::reverse(sf::Time dt) {
    if (velocity > 0.f) {
        velocity -= brakeForce * acceleration * dt.asSeconds();
    } else {
        velocity -= acceleration * dt.asSeconds();
    }

    if (velocity < -maxSpeed/2.f) {
        velocity = -maxSpeed/2.f;
    }
}

void Car::turn(TurnTypes turn, sf::Time dt) {
    float modifier = 0.f;
    if (velocity != 0.f){
        modifier = (turn == TurnTypes::LEFT) ? -1.f : 1.f;
    }
    angle = angle + modifier * rotation * dt.asSeconds();
}

void Car::updatePos(sf::Time dt) {
    position.x += slowModifier * velocity * std::sin(angle.asRadians()) * dt.asSeconds();
    position.y -= slowModifier * velocity * std::cos(angle.asRadians()) * dt.asSeconds();
}

void Car::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Car::setSlow(float slow) {
    slowModifier = slow;
}

sf::Vector2f Car::getPosition() const {
    return position;
}

sf::Vector2f Car::getSize() const {
    return size;
}

sf::Angle Car::getAngle() const {
    return angle;
}

float Car::getSlowModifier() const {
    return slowModifier;
}
