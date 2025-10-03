//
// Created by jakub on 30.09.2025.
//

#include "Tile.h"

Tile::Tile(sf::Vector2f size, sf::Vector2f position, TileTypes type):
    size(size),
    position(position),
    type(type){}

sf::Vector2f Tile::getSize() {
    return size;
}

sf::Vector2f Tile::getPosition() {
    return position;
}

TileTypes Tile::getType() {
    return type;
}

void Tile::setPosition(sf::Vector2f position) {
    this->position = position;
}
