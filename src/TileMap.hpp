#pragma once
#include "Tile.hpp"
#include <string>
#include <unordered_map>

class TileMap {
    std::unordered_map<Hex, Tile> tiles;
    std::string map_name;

    public:
    TileMap(std::unordered_map<Hex, Tile> tiles, std::string map_name);


};