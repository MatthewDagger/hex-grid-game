#include "Unit.hpp"


void Unit::set_location(Hex& destination) {
    location = destination;
}

Hex Unit::get_location() {
    return location;
}
