#include "TileMap.hpp"

TileMap::TileMap(std::unordered_map<Hex, Tile> tiles, std::string map_name):
    tiles(tiles), map_name(map_name) {

    };
