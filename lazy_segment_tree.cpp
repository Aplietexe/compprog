#define NEUT 0
#define LNEUT 0
struct STree
{
    vll st, lazy;
    ll n;
    STree(ll n) : st(4 * n + 5, NEUT), lazy(4 * n + 5, LNEUT), n(n) {}
    void _init(ll k, ll s, ll e, vll &a)
    {
        lazy[k] = LNEUT;
        if (s + 1 == e)
        {
            st[k] = a[s];
            return;
        }
        ll m = (s + e) / 2;
        _init(2 * k, s, m, a);
        _init(2 * k + 1, m, e, a);
        st[k] = st[2 * k] + st[2 * k + 1]; // operation
    }
    void push(ll k, ll s, ll e)
    {
        if (lazy[k] == LNEUT)
            return;
        st[k] += (e - s) * lazy[k]; // update st according to lazy
        if (s + 1 < e)
        {
            lazy[2 * k] += lazy[k];     // acc
            lazy[2 * k + 1] += lazy[k]; // acc
        }
        lazy[k] = LNEUT; // clear node lazy
    }
    void _upd(ll k, ll s, ll e, ll a, ll b, ll v)
    {
        push(k, s, e);
        if (s >= b || e <= a)
            return;
        if (s >= a && e <= b)
        {
            lazy[k] += v; // acc
            push(k, s, e);
            return;
        }
        ll m = (s + e) / 2;
        _upd(2 * k, s, m, a, b, v);
        _upd(2 * k + 1, m, e, a, b, v);
        st[k] = st[2 * k] + st[2 * k + 1]; // operation
    }
    ll _query(ll k, ll s, ll e, ll a, ll b)
    {
        if (s >= b || e <= a)
            return NEUT;
        push(k, s, e);
        if (s >= a && e <= b)
            return st[k];
        ll m = (s + e) / 2;
        return _query(2 * k, s, m, a, b) + _query(2 * k + 1, m, e, a, b); // operation
    }
    void init(vll &a) { _init(1, 0, n, a); }
    void upd(ll a, ll b, ll v) { _upd(1, 0, n, a, b, v); }
    ll query(ll a, ll b) { return _query(1, 0, n, a, b); }
};
