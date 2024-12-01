#include "Game.hpp"

int main(){
    std::unordered_map<Hex, Tile> hex_map;
    hex_map.insert({Hex(0,0,0), Tile(Hex(0,0,0))});
    hex_map.insert({Hex(1,-1,0), Tile(Hex(1,-1,0))});

    TileMap map = TileMap(hex_map, "Test Map");
    Game game = Game(map);
}