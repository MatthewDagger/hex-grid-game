#pragma once
#include "Hex.hpp"

// Abstract class to represnt any unit on the board
class Unit {
    Hex location;
public:
    Hex get_location();
    void set_location(Hex& destination);
};
