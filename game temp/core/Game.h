//
// Created by jakub on 20.09.2025.
//

#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "Controller.h"
#include "CollisionManager.h"
#include "../ui/Renderer.h"
#include "../world/Map.h"

class Game {
public:
    Game();
    ~Game();
    void setUp();
    void run();

private:
    sf::RenderWindow* window;
    Controller controller;

    Map map;
    // CollisionManager collisionManager;
    // Renderer renderer;
};



#endif //GAME_H
