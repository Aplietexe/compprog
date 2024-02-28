constexpr lll abs(lll& v) { return v < 0 ? -v : v; }
istream& operator>>(istream& is, lll& value) {
    ll x;
    is >> x;
    value = x;
    return is;
}
ostream& operator<<(ostream& os, lll value) {
    if (value < 0) {
        os << '-';
        value = -value;
    }
    if (numeric_limits<unsigned long long>::max() >= value) return os << (unsigned long long)value;
    string s;
    do {
        s += (char)(value % 10 + '0');
        value /= 10;
    } while (value);
    rof(i, SZ(s), 0) os << s[i];
    return os;
}
