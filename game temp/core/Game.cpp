//
// Created by jakub on 20.09.2025.
//

#include "Game.h"

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
    while (window->isOpen()) {
        if (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }


    }
}
