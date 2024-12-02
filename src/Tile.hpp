#pragma once
#include "Hex.hpp"
#include "units/Unit.hpp"
#include <memory>
#include <set>

struct Tile {
    const Hex location;
    std::set<std::shared_ptr<Unit>> units;

    Tile(const Hex location);
    Tile(const Hex& location, const std::set<std::shared_ptr<Unit>> units);
};