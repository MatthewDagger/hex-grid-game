/// @brief Hextypes are genreated to handle vectors and both types of number
/// @tparam Number 
/// @tparam vector 
template <typename Number>
struct _Hex {
    union {
        const Number v[3];
        struct { const Number q, r, s;};
    };
    
    _Hex(Number q_, Number r_, Number s_): v{ q_, r_, s_ } {
        assert (q + r + s == 0)
    };
    _Hex(Number q_, Number r_): v{ q_, r_, - q_ - r_ } {};

    bool operator == (const _Hex& a) {
        return a.q == q && a.r == r && a.s == s;
    }

    bool operator != (const _Hex& a) {
        return !(this == a)
    }

    /// @brief Calculates the vector length of this hex (from 0,0,0 to q,r,s)
    /// @return The length in hexes
    Number get_length() {
        return Number((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
    }


};
typedef _Hex<int> Hex;
typedef _Hex<double> FractionalHex;


// /// @brief Adds two hex positions together
// /// @param a 
// /// @param b 
// /// @return 
Hex hex_add(Hex a, Hex b) {
    return Hex(a.q + b.q, a.r + b.r, a.s + b.s);
}

/// @brief 
/// @param a 
/// @param b 
/// @return 
Hex hex_subtract(Hex a, Hex b) {
    return Hex(a.q - b.q, a.r - b.r, a.s - b.s);
}

/// @brief Multiplies a hex by some scalar
/// @param a 
/// @param k The scalar to multiply by
/// @return 
Hex hex_multiply(Hex a, int k) {
    return Hex(a.q * k, a.r * k, a.s * k);
}

int hex_distance(Hex a, Hex b) {
    return hex_subtract(a, b).get_length();
}


FractionalHex a = FractionalHex(1.0,2,3);
Hex b = Hex(1,2,3);
bool check = a == a;

int c = b.get_length();