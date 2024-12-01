#pragma once
#include <cassert>
#include <cmath>
#include <vector>
#include <functional>

/// @brief Hextypes are generated to both types of number
/// @tparam Number
template <typename Number>
struct _Hex {
    union {
        const Number v[3];
        struct { const Number q, r, s; };
    };

    _Hex(Number q_, Number r_, Number s_);
    _Hex(Number q_, Number r_);

    bool operator==(const _Hex& a) const;
    bool operator!=(const _Hex& a) const;

    _Hex operator+(const _Hex& a) const;
    _Hex operator-(const _Hex& a) const;

    template <typename Scalar>
    _Hex operator*(Scalar k) const;

    Number get_length() const;
    Number distance_to(const _Hex& a) const;
    _Hex get_neighbour(int direction);
};

typedef _Hex<int> Hex;
typedef _Hex<double> FractionalHex;

// Holds the directional vector for hexes
extern const std::vector<Hex> hex_directions;

// Getter for directions
Hex hex_direction(int direction);

// Hash function
namespace std {
    template <> struct hash<Hex> {
        size_t operator()(const Hex& h) const;
    };
}