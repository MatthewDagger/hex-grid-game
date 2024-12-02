#include "Hex.hpp"

// _Hex Implementation
template <typename Number>
_Hex<Number>::_Hex(Number q_, Number r_, Number s_) : v{q_, r_, s_} {
    assert(q + r + s == 0);
}

template <typename Number>
_Hex<Number>::_Hex(Number q_, Number r_) : v{q_, r_, -q_ - r_} {}

template <typename Number>
bool _Hex<Number>::operator==(const _Hex& a) const {
    return a.q == q && a.r == r && a.s == s;
}

template <typename Number>
bool _Hex<Number>::operator!=(const _Hex& a) const {
    return !(*this == a);
}

template <typename Number>
_Hex<Number> _Hex<Number>::operator+(const _Hex& a) const {
    return _Hex(q + a.q, r + a.r, s + a.s);
}

template <typename Number>
_Hex<Number> _Hex<Number>::operator-(const _Hex& a) const {
    return _Hex(q - a.q, r - a.r, s - a.s);
}

template <typename Number>
template <typename Scalar>
_Hex<Number> _Hex<Number>::operator*(Scalar k) const {
    return _Hex(q * k, r * k, s * k);
}

template <typename Number>
Number _Hex<Number>::get_length() const {
    return Number((std::abs(q) + std::abs(r) + std::abs(s)) / 2);
}

template <typename Number>
Number _Hex<Number>::distance_to(const _Hex& a) const {
    return (*this - a).get_length();
}

template <typename Number>
_Hex<Number> _Hex<Number>::get_neighbour(int direction) {
    return *this + hex_direction(direction);
}

template <typename Number>
std::vector<_Hex<Number>> _Hex<Number>::hex_directions = {
    _Hex(1, 0, -1), _Hex(1, -1, 0), _Hex(0, -1, 1),
    _Hex(-1, 0, 1), _Hex(-1, 1, 0), _Hex(0, 1, -1)
};

template <typename Number>
_Hex<Number> _Hex<Number>::hex_direction(int direction) {
    assert(0 <= direction && direction <= 5);
    return hex_directions[direction];
}

// Explicit instantiations for _Hex<int> and _Hex<double>
template struct _Hex<int>;
template struct _Hex<double>;

namespace std {
    size_t hash<Hex>::operator()(const Hex& h) const {
        hash<int> int_hash;
        size_t hq = int_hash(h.q);
        size_t hr = int_hash(h.r);
        return hq ^ (hr + 0x9e3779b9 + (hq << 6) + (hq >> 2));
    }
}

