#pragma once
#include "Hex.hpp"

// Abstract class to represnt any unit on the board
class Unit {
public:
    virtual Hex get_location() = 0;
};
