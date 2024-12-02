#pragma once
#include "TileMap.hpp"

class Game{
    TileMap map;
    std::list<Unit*> player_units;
    std::list<Unit*> npc_units;

    public:
    Game(TileMap& map);
    
    void step();

    // Unit Movement
    void move_unit(Unit* unit, Hex& destination);
    std::list<Hex> generate_path(Hex& origin, Hex& destination);
};


