//
// Created by jakub on 20.09.2025.
//

#include "Game.h"

#include <iostream>

#include "../entities/Car.h"
#include "../world/MapLoader.h"
#include "SFML/Graphics/RectangleShape.hpp"

Game::Game(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Car Racing", sf::Style::Default,
                                  sf::State::Windowed, settings);
}

Game::~Game() {
    delete window;
}

void Game::setUp() {
    map = MapLoader::loadMap("race_track.txt", {20.f, 20.f});
}

void Game::run() {
    sf::Clock clock;
    clock.restart();
    sf::Time tick = clock.getElapsedTime();
    sf::Time dt;

    //TMP
    sf::RectangleShape carRect = sf::RectangleShape({100,200});
    carRect.setPosition({200,200});
    carRect.setOrigin({50,100});
    carRect.setFillColor(sf::Color::White);

    Car car({100,200}, 300.f, 500, sf::degrees(60.f), 3.f, 0.5f);
    car.setPosition({200,200});
    //


    while (window->isOpen()) {
        //Delta Time
        sf::Time tmpTime = clock.getElapsedTime();
        dt = tmpTime - tick;
        tick = tmpTime;

        if (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        
        controller.update(dt, car);


        carRect.setPosition(car.getPosition());
        carRect.setRotation(car.getAngle());


        window->clear();
        window->draw(carRect);
        window->display();
    }
}
