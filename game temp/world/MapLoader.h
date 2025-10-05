//
// Created by jakub on 04.10.2025.
//

#ifndef MAPREADER_H
#define MAPREADER_H
#include <string>

#include "Map.h"


class MapLoader {
public:
    static Map loadMap(const std::string &filePath, sf::Vector2f tileSize);
};


#endif //MAPREADER_H
