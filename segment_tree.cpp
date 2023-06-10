#define oper min
#define NEUT INF
struct STree
{
    vll st;
    ll n;
    STree(ll n) : st(4 * n + 5, NEUT), n(n) {}
    void _init(ll k, ll s, ll e, vll &a)
    {
        if (s + 1 == e)
        {
            st[k] = a[s];
            return;
        }
        ll m = (s + e) / 2;
        _init(2 * k, s, m, a);
        _init(2 * k + 1, m, e, a);
        st[k] = oper(st[2 * k], st[2 * k + 1]);
    }
    void _upd(ll k, ll s, ll e, ll p, ll v)
    {
        if (s + 1 == e)
        {
            st[k] = v;
            return;
        }
        ll m = (s + e) / 2;
        if (p < m)
            _upd(2 * k, s, m, p, v);
        else
            _upd(2 * k + 1, m, e, p, v);
        st[k] = oper(st[2 * k], st[2 * k + 1]);
    }
    ll _query(ll k, ll s, ll e, ll a, ll b)
    {
        if (s >= b || e <= a)
            return NEUT;
        if (s >= a && e <= b)
            return st[k];
        ll m = (s + e) / 2;
        return oper(_query(2 * k, s, m, a, b), _query(2 * k + 1, m, e, a, b));
    }
    void init(vll &a) { _init(1, 0, n, a); }
    void upd(ll p, ll v) { _upd(1, 0, n, p, v); }
    ll query(ll a, ll b) { return _query(1, 0, n, a, b); } // [s, e)
};
