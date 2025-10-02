//
// Created by jakub on 20.09.2025.
//

#include "Game.h"

#include <iostream>

#include "../entities/Car.h"
#include "SFML/Graphics/RectangleShape.hpp"

Game::Game() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"Car Racing", sf::Style::Default, sf::State::Windowed, settings);
}

Game::~Game() {
    delete window;
}

void Game::setUp() {
}

void Game::run() {
    sf::Clock clock;
    clock.restart();
    sf::Time dt = clock.getElapsedTime();

    sf::RectangleShape carRect = sf::RectangleShape({100,200});
    carRect.setPosition({200,200});
    carRect.setOrigin({50,100});
    carRect.setFillColor(sf::Color::White);

    Car car({100,200}, 0.00005f, 0.5, sf::degrees(0.015f), 1);
    car.setPosition({200,200});
//Car::Car(sf::Vector2f size, float acceleration, float maxSpeed, sf::Angle rotation, float brakeForce):


    while (window->isOpen()) {
        dt = clock.getElapsedTime() - dt;
        if (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            car.accelerate(dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            car.brake(dt);
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
        carRect.setPosition(car.getPosition());
        carRect.setRotation(car.getAngle());




        window->clear();
        window->draw(carRect);
        window->display();



    }
}
