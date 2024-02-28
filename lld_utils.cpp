constexpr lld abs(lld val) { return val < 0 ? -val : val; }
ostream& operator<<(ostream& os, lld val) {
    return os << (ld)val;
}
istream& operator>>(istream& is, lld& val) {
    ld x;
    return is >> x, val = x, is;
}
