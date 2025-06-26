#pragma once
#include "TileMap.hpp"

class Game{
    public:
    TileMap map;
    std::list<Unit*> player_units;
    std::list<Unit*> npc_units;

    Game(TileMap& map);
    
    void step();

    // Unit Movement
    void move_unit(Unit* unit, const Hex& destination);
    std::list<Hex> generate_path(const Hex& origin, const Hex& destination);
};


