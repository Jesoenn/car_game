//
// Created by jakub on 30.09.2025.
//

#include "Map.h"

#include <stdexcept>
#include <utility>

Map::Map() = default;

Map::Map(sf::Vector2f tileSize, std::vector<std::vector<TileTypes>> tiles):
    tileSize(tileSize),
    tiles(std::move(tiles)) {
    if (this->tiles.empty() || this->tiles[0].empty()) {
        throw std::invalid_argument("Map is empty");
    }

    mapSize = sf::Vector2i(static_cast<int>(this->tiles[0].size()), static_cast<int>(this->tiles.size()));
}

bool Map::isOnGrass(sf::Vector2f position) {
    // Sprawdzic czy mapsize/position zaokraglone czy map[x][y] pasuje

}

TileTypes Map::getTile(sf::Vector2f position) {
    int y = static_cast<int>(position.y/tileSize.y);
    int x = static_cast<int>(position.x/tileSize.x);
    return tiles[y][x];
}

sf::Vector2f Map::getStart() {

}

sf::Vector2f Map::getTileSize() {
    return tileSize;
}

sf::Vector2i Map::getSize() {
    return mapSize;
}
