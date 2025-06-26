#include "HexUtils.hpp"


namespace HexUtils {
    // Stores information about the current orientation of the board. 
    // f and b doubles form the transformation matrices for hex conversion to and from pixels
    // === Orientation Constructor ===
    Orientation::Orientation(double f0_, double f1_, double f2_, double f3_,
        double b0_, double b1_, double b2_, double b3_,
        double start_angle_)
        : f0(f0_), f1(f1_), f2(f2_), f3(f3_),
        b0(b0_), b1(b1_), b2(b2_), b3(b3_),
        start_angle(start_angle_) {
    }

    // === Layout Constructor ===
    Layout::Layout(Orientation orientation_, Vector2 size_, Vector2 origin_)
        : orientation(orientation_), size(size_), origin(origin_) {
    }

    // Default two layouts for ease of access
    const Orientation layout_pointy
        = Orientation(sqrt(3.0), sqrt(3.0) / 2.0, 0.0, 3.0 / 2.0,
            sqrt(3.0) / 3.0, -1.0 / 3.0, 0.0, 2.0 / 3.0,
            0.5);
    const Orientation layout_flat
        = Orientation(3.0 / 2.0, 0.0, sqrt(3.0) / 2.0, sqrt(3.0),
            2.0 / 3.0, 0.0, -1.0 / 3.0, sqrt(3.0) / 3.0,
            0.0);


    // Get center pixel of a hex
    Vector2 hex_to_pixel(Layout layout, Hex h) {
        const Orientation& M = layout.orientation;
        double x = (M.f0 * h.q + M.f1 * h.r) * layout.size.x;
        double y = (M.f2 * h.q + M.f3 * h.r) * layout.size.y;
        return Vector2Add(Vector2(x ,y), layout.origin);
    }

    // Get vector for a given corner of a hex
    Vector2 hex_corner_offset(Layout layout, int corner) {
        // In radians
        double angle = 2.0 * M_PI *
            (layout.orientation.start_angle + corner) / 6;
        return Vector2Multiply(layout.size, Vector2( cos(angle), sin(angle)));
    }

    std::vector<Vector2> polygon_corners(Layout layout, Hex h) {
        std::vector<Vector2> corners = {};
        Vector2 center = hex_to_pixel(layout, h);
        for (int i = 0; i < 6; i++) {
            Vector2 offset = hex_corner_offset(layout, i);
            corners.push_back(Vector2Add(center, offset));
        }
        return corners;
    }
}
