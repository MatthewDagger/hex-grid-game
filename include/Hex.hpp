#pragma once
#include <cassert>
#include <cmath>
#include <vector>
#include <string>
#include <functional>
#include <format>
#include <unordered_map>

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
    

    _Hex& operator=(const _Hex& a);

    _Hex operator+(const _Hex& a) const;
    _Hex operator-(const _Hex& a) const;

    template <typename Scalar>
    _Hex operator*(Scalar k) const;

    Number get_length() const;
    Number distance_to(const _Hex& a) const;
    _Hex get_neighbour(int direction);

    static std::vector<_Hex> hex_directions;
    static _Hex hex_direction(int direction);
    std::string to_string() const;
};

typedef _Hex<int> Hex;
typedef _Hex<double> FractionalHex;

// Hash function
namespace std {
    template <> struct hash<Hex> {
        size_t operator()(const Hex& h) const;
    };
}

