#include "Game.hpp"
#include <iostream>
#include <BasicRenderer.hpp>

// Util function for testing
static TileMap generate_hexagonal_map(const int size) {
    std::unordered_map<Hex, Tile> hex_map;

    // Generate a hexagonal map https://www.redblobgames.com/grids/hexagons/implementation.html#map-storage
    for (int q = -size; q <= size; q++) {
        int r1 = std::max(-size, -q - size);
        int r2 = std::min(size, -q + size);
        for (int r = r1; r <= r2; r++) {
            hex_map.insert({ Hex(q, r, -q - r), Tile(Hex(q, r, -q - r)) });
        }
    }

    return TileMap(hex_map, "Test Map");

}

int main(){

    TileMap map = generate_hexagonal_map(5);
    Game game = Game(map);

    BasicRenderer renderer = BasicRenderer(game);
    renderer.render();

    
}

