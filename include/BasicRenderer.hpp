#pragma once
#include "Game.hpp"
#include "raylib.h"
#include "HexUtils.hpp"

class BasicRenderer{
    Game game;

    public:
    BasicRenderer(Game& game);
    
    void render();
};


