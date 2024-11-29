#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

/// @brief Hextypes are genreated to both types of number
/// @tparam Number 
/// @tparam vector 
template <typename Number>
struct _Hex {
    union {
        const Number v[3];
        struct { const Number q, r, s;};
    };
    
    _Hex(Number q_, Number r_, Number s_): v{ q_, r_, s_ } {
        assert(q + r + s == 0);
    };

    _Hex(Number q_, Number r_): v{ q_, r_, - q_ - r_ } {};

    bool operator == (const _Hex& a) const {
        return a.q == q && a.r == r && a.s == s;
    }

    bool operator != (const _Hex& a) const {
        return !(*this == a);
    }

    _Hex operator + (const _Hex& a) const {
        return _Hex( q + a.q, r + a.r, s + a.s );
    }

    _Hex operator - (const _Hex& a) const {
        return _Hex(q - a.q, r - a.r, s - a.s);
    }

    template <typename Scalar>
    _Hex operator * (Scalar k) const {
        return _Hex(q * k, r * k, s * k);
    }

    // @brief Calculates the vector length of this hex (from 0,0,0 to q,r,s)
    // @return The length in hexes
    Number get_length() const {
        return Number((abs(q) + abs(r) + abs(s)) / 2);
    }

    // @brief Calculates the hex distance to another hex
    // @param a The other hex
    // @return The distance in hexes
    Number distance_to(const _Hex& a) const {
        return (*this - a).get_length();
    }

    // @brief Gets the neighbouring hex to this in a specific direction
    // @param direction The direction to look for a neighbour in
    // @return The neighbouring hex
    _Hex get_neighbour(int direction) {
        return *this + hex_direction(direction);
    }

};
typedef _Hex<int> Hex;
typedef _Hex<double> FractionalHex;


// Holds the directional vector for hexes
const vector<Hex> hex_directions = {
    Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
    Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};

// Getter for directions
Hex hex_direction(int direction) {
    assert(0 <= direction <= 5);
    return hex_directions[direction];
}


int main() {
    FractionalHex a = FractionalHex(0, 0, 0);
    Hex b = Hex(1, -2, 1);
    bool check = a == a;

}

