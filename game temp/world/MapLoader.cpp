//
// Created by jakub on 04.10.2025.
//

#include "MapLoader.h"

#include <fstream>
#include <iostream>

Map MapLoader::loadMap(const std::string &filePath, const sf::Vector2f tileSize) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::invalid_argument("File \"rarce_track.txt\" could not be opened");
    }

    std::string line;
    std::vector<std::vector<TileTypes>> tiles;   //whole map
    while (std::getline(file, line)) {  //read row
        std::vector<TileTypes> tileRow;
        for (char i: line) {
            //TileTypes: ASPHALT, GRASS, START, CHECKPOINT
            switch (i) {
                case 'A': tileRow.emplace_back(TileTypes::ASPHALT); break;
                case 'G': tileRow.emplace_back(TileTypes::GRASS); break;
                case 'S': tileRow.emplace_back(TileTypes::START); break;
                case 'C': tileRow.emplace_back(TileTypes::CHECKPOINT); break;
                default: throw std::invalid_argument("Wrong map format!");
            }
        }
        tiles.push_back(tileRow);
    }

    std::cout<<tiles[0].size()<<std::endl;
    std::cout<<tiles.size()<<std::endl;


    file.close();
    return {tileSize, tiles};
}
