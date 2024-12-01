#include "TileMap.hpp"

TileMap::TileMap(std::unordered_map<Hex, Tile> _tiles, std::string _map_name):
    tiles(_tiles), map_name(_map_name) {

    };
