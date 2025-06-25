#pragma once
#include "Game.hpp"

class BasicRenderer{
    Game game;

    public:
    BasicRenderer(Game& game);
    
    void render();
};


