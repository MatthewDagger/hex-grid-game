#include "BasicRenderer.hpp"

BasicRenderer::BasicRenderer(Game& game): game(game) {}

void BasicRenderer::render(){
    // Initialise layout
    const Layout layout = Layout(orientation_point, Vector2(50,50), Vector2(400, 300));

    InitWindow(800, 600, "Test");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (auto const& [_h, t] : game.map.tiles) {
            draw_tile(t, layout);
        }
        EndDrawing();
    }
    CloseWindow();
}


