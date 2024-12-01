#pragma once
#include "Tile.hpp"
#include <string>

class TileMap {
    std::unordered_map<Hex, Tile> tiles;
    std::string map_name;

    public:
    TileMap(std::unordered_map<Hex, Tile> _tiles, std::string _map_name);


};