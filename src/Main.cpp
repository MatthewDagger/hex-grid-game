#include "Game.hpp"
#include <iostream>
int main(){
    std::unordered_map<Hex, Tile> hex_map;
    for (size_t i = 0; i < 5; i++)
    {
        hex_map.insert({ Hex(i,-i,0), Tile(Hex(i,-i,0)) });
        hex_map.insert({ Hex(i,0,-i), Tile(Hex(i,0,-i)) });
        hex_map.insert({ Hex(-i,0,i), Tile(Hex(-i,0,i)) });
        hex_map.insert({ Hex(-i,i,0), Tile(Hex(-i,i,0)) });
        hex_map.insert({ Hex(0,i,-i), Tile(Hex(0,i,-i)) });
        hex_map.insert({ Hex(0,-i,i), Tile(Hex(0,-i,i)) });
    };

    TileMap map = TileMap(hex_map, "Test Map");
    Game game = Game(map);


    std::list<Hex> path = game.generate_path(Hex(0, 1, -1), Hex(4, 0, -4));

    for each(Hex hex in path)
    {
        std::cout << hex.q << hex.r << hex.s << "\n";
    }


    
}