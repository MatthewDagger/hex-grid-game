#include "BasicRenderer.hpp"
#include "raylib.h"
#include "HexUtils.hpp"

BasicRenderer::BasicRenderer(Game& game): game(game) {}

void BasicRenderer::render(){
    InitWindow(800, 600, "Hello Raylib!");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        /*DrawLineStrip(vertices, 6, color);*/

        EndDrawing();
    }
    CloseWindow();
}


