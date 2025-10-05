//
// Created by jakub on 30.09.2025.
//

#ifndef MAP_H
#define MAP_H

#include <vector>
#include "../entities/Tile.h"

class Map {
public:
    Map();
    Map(sf::Vector2f tileSize, std::vector<std::vector<TileTypes>> tiles);

    bool isOnGrass(sf::Vector2f position);

    //Getters
    TileTypes getTile(sf::Vector2f position);
    sf::Vector2f getStart();
    sf::Vector2f getTileSize();
    sf::Vector2i getSize();


private:
    sf::Vector2i mapSize;
    sf::Vector2f tileSize;
    std::vector<std::vector<TileTypes>> tiles;
};



#endif //MAP_H
