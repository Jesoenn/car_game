//
// Created by jakub on 20.09.2025.
//

#ifndef GAME_H
#define GAME_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "Input.h"
#include "CollisionManager.h"
#include "../ui/Renderer.h"

class Game {
public:
    Game();
    ~Game();
    void setUp();
    void run();

private:
    sf::RenderWindow* window;
    // Input input;
    // CollisionManager collisionManager;
    // Renderer renderer;
};



#endif //GAME_H
