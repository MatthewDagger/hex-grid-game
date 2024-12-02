#include "Tile.hpp"

Tile::Tile(Hex location): location(location) {
    
}

Tile::Tile(const Hex& location, const std::set<std::shared_ptr<Unit>> units)
    : location(location), units(units) {
}
