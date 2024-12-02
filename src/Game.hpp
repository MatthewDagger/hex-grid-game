#pragma once
#include "TileMap.hpp"

class Game{
    TileMap map;

    public:
    Game(TileMap& map);
    
    void move_unit(Unit unit, Hex destination);
};