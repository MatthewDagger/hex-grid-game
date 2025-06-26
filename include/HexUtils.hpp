#pragma once

#define _USE_MATH_DEFINES
#include "Hex.hpp"
#include <cmath>
#include <raylib.h>
#include <raymath.h>
#include <Tile.hpp>
#include <vector>

struct Orientation {
    const double f0, f1, f2, f3;
    const double b0, b1, b2, b3;
    const double start_angle;

    Orientation(double f0_, double f1_, double f2_, double f3_,
        double b0_, double b1_, double b2_, double b3_,
        double start_angle_);
};

extern const Orientation orientation_point;
extern const Orientation orientation_flat;

struct Layout {
    const Orientation orientation;
    const Vector2 size;
    const Vector2 origin;

    Layout(Orientation orientation_, Vector2 size_, Vector2 origin_);
};

// Convert hex coordinate to pixel position
Vector2 hex_to_pixel(Layout layout, Hex h);

// Get pixel offset to a hex corner
Vector2 hex_corner_offset(Layout layout, int corner);

// Get all 6 corners of a hex in screen coordinates
std::vector<Vector2> polygon_corners(Layout layout, Hex h);

// Draw a tile
void draw_tile(Tile t, Layout layout);