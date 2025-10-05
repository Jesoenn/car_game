//
// Created by jakub on 30.09.2025.
//

#ifndef TILE_H
#define TILE_H


#include "../enums/TileTypes.h"
#include "SFML/System/Vector2.hpp"

//Origin of tile is middle
class Tile {
public:
    Tile(sf::Vector2f size, sf::Vector2f position, TileTypes type);

    //Getters
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    TileTypes getType();

    //Setters
    void setPosition(sf::Vector2f position);


private:
    const sf::Vector2f size;
    const TileTypes type;
    sf::Vector2f position;
};



#endif //TILE_H
