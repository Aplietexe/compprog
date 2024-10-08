const ld inf = numeric_limits<ld>::infinity();
struct HyperDual {  // extension of dual numbers for autodiff of second order
    ld x, e1, e2, e1e2;
    HyperDual(ld x, ld e1 = 0, ld e2 = 0, ld e1e2 = 0) : x(x), e1(e1), e2(e2), e1e2(e1e2) {}
    HyperDual operator+(const HyperDual& a) const {
        return HyperDual(x + a.x, e1 + a.e1, e2 + a.e2, e1e2 + a.e1e2);
    }
    HyperDual operator-(const HyperDual& a) const {
        return HyperDual(x - a.x, e1 - a.e1, e2 - a.e2, e1e2 - a.e1e2);
    }
    HyperDual operator*(const HyperDual& a) const {
        return HyperDual(
            x * a.x,
            x * a.e1 + e1 * a.x,
            x * a.e2 + e2 * a.x,
            x * a.e1e2 + e1 * a.e2 + e2 * a.e1 + e1e2 * a.x);
    }
    HyperDual inv() const {
        ld sq = x * x;
        return HyperDual(
            1 / x,
            -e1 / sq,
            -e2 / sq,
            (2 * e1 * e2) / (sq * x) - e1e2 / sq);
    }
    HyperDual operator/(const HyperDual& a) const { return *this * a.inv(); }
    HyperDual operator<(const HyperDual& a) const { return x < a.x; }
};
// f(x + a\epsilon_{1} + b\epsilon_{2} + c \epsilon_{1}\epsilon_{2}) = f(x) + \epsilon_{1}a f'(x) + \epsilon_{2}bf'(x) + \epsilon_{1} \epsilon_{2} (a b f''(x) + c f'(x))
HyperDual cos(const HyperDual& a) {
    ld c = cos(a.x), s = sin(a.x);
    return HyperDual(c, -s * a.e1, -s * a.e2, -c * a.e1 * a.e2 - s * a.e1e2);
}
HyperDual sin(const HyperDual& a) {
    ld c = cos(a.x), s = sin(a.x);
    return HyperDual(s, c * a.e1, c * a.e2, -s * a.e1 * a.e2 + c * a.e1e2);
}
HyperDual tan(const HyperDual& a) {
    return sin(a) / cos(a);
}
HyperDual sqrt(const HyperDual& a) {
    if (a.x < 1e-15) return {0, inf, inf, abs(a.e1 * a.e2) < 1e-15 ? abs(a.e1e2) < 1e-15 ? 0 : copysignl(inf, a.e1e2) : copysignl(inf, a.e1 * a.e2)};
    ld s = sqrtl(a.x), t = 1 / (2 * s);
    return HyperDual(
        s,
        t * a.e1,
        t * a.e2,
        -a.e1 * a.e2 / (4 * s * s * s) + t * a.e1e2);
}

HyperDual newtonRoot(function<HyperDual(HyperDual)> f, ld x) {
    fore(i, 0, 4) {
        HyperDual y = f({x, 1, 0, 0});
        x -= y.x / y.e1;
    }
    return x;
}

HyperDual newtonCritical(function<HyperDual(HyperDual)> f, ld x) {
    fore(i, 0, 4) {
        HyperDual y = f({x, 1, 1, 0});
        x -= y.e1 / y.e1e2;
    }
    return x;
}
