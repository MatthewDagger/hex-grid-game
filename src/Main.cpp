#include "Game.hpp"
#include <iostream>
int main(){
    std::unordered_map<Hex, Tile> hex_map;

    // Generate a hexagonal map https://www.redblobgames.com/grids/hexagons/implementation.html#map-storage
    const int size = 5;
    for (int q = -size; q <= size; q++) {
        int r1 = std::max(-size, -q - size);
        int r2 = std::min(size, -q + size);
        for (int r = r1; r <= r2; r++) {
            hex_map.insert({ Hex(q, r, -q - r), Tile(Hex(q, r, -q - r)) });
        }
    }

    TileMap map = TileMap(hex_map, "Test Map");
    Game game = Game(map);

    std::list<Hex> path = game.generate_path(Hex(0, 2, -2), Hex(2, -2, 0));


    for (Hex h: path)
    {
        std::cout << h.to_string() << "\n";
    }

    
}