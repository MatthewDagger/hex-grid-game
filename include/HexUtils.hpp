#pragma once

#define _USE_MATH_DEFINES
#include <raylib.h>
#include <raymath.h>
#include <cmath>
#include <vector>
#include "Hex.hpp"


namespace HexUtils {

    struct Orientation {
        const double f0, f1, f2, f3;
        const double b0, b1, b2, b3;
        const double start_angle;

        Orientation(double f0_, double f1_, double f2_, double f3_,
            double b0_, double b1_, double b2_, double b3_,
            double start_angle_);
    };

    extern const Orientation layout_pointy;
    extern const Orientation layout_flat;

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

} 
