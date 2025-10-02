//
// Created by jakub on 30.09.2025.
//

#include "Car.h"

#include <complex>

Car::Car(sf::Vector2f size, float acceleration, float maxSpeed, sf::Angle rotation, float brakeForce):
    size(size),
    acceleration(acceleration),
    maxSpeed(maxSpeed),
    brakeForce(brakeForce),
    rotation(rotation),
    angle(sf::radians(0)),
    position({0.f,0.f}),
    velocity(0.f){}

//W key
void Car::accelerate(sf::Time dt) {
    velocity += acceleration * dt.asSeconds();
    if (velocity > maxSpeed) {
        velocity = maxSpeed;
    }
}

//Nothing
void Car::decelerate(sf::Time dt) {
    float originalVelocity = velocity;

    if (velocity < 0.f) {
        velocity += 0.5* acceleration * dt.asSeconds();
    } else if (velocity > 0.f) {
        velocity -= 0.5*acceleration * dt.asSeconds();
    }

    if (originalVelocity > 0.f && velocity < 0.f || originalVelocity < 0.f && velocity > 0) {
        velocity = 0.f;
    }


    if (velocity < -maxSpeed) {
        velocity = -maxSpeed;
    }
}

//S key
void Car::brake(sf::Time dt) {
    velocity -= brakeForce * acceleration * dt.asSeconds();
    if (velocity < -maxSpeed) {
        velocity = -maxSpeed;
    }
}

void Car::turn(TurnTypes turn, sf::Time dt) {
    float modifier = (turn == TurnTypes::LEFT) ? -1.f : 1.f;
    angle = angle + modifier * rotation * dt.asSeconds();
}

void Car::updatePos() {
    position.x += velocity * std::sin(angle.asRadians());
    position.y -= velocity * std::cos(angle.asRadians());
}

void Car::setPosition(sf::Vector2f position) {
    this->position = position;
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
