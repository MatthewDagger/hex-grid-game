#pragma once
#include "Tile.hpp"
#include <string>
#include <unordered_map>

class TileMap {
    public:
    std::unordered_map<Hex, Tile> tiles;
    std::string map_name;

    TileMap(std::unordered_map<Hex, Tile> tiles, std::string map_name);


};