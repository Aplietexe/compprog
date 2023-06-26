bool is_prime(ll n)
{
    if (n % 2 == 0)
        return n == 2;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return n >= 2;
}

vll divisors(ll n)
{
    vll res;

    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            res.pb(i);
            if (i != n / i)
                res.pb(n / i);
        }

    return res;
}

vpll p_factors(ll n)
{
    vpll res;

    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res.pb({i, 0});
            while (n % i == 0)
            {
                n /= i;
                res.back().snd++;
            }
        }

    if (n > 1)
        res.pb({n, 1});
    return res;
}

vector<int> cr(MAXN, -1); // -1 if 0, 1 or prime. The smallest prime divisor otherwise
void init_sieve()
{
    fori(i, 2, MAXN)
    {
        if (cr[i] < 0)
            for (ll j = i * i; j < MAXN; j += i)
                if (cr[j] < 0)
                    cr[j] = i;
    }
}

vector<pair<int, int>> sieve_fact(int n)
{
    if (n == 1)
        return {};
    if (cr[n] == -1)
        return {{n, 1}};
    vector<pair<int, int>> r;
    ll last = 0;
    while (cr[n] >= 0)
    {
        if (cr[n] != last)
            r.pb({cr[n], 0}), last = cr[n];
        r.back().snd++;
        n /= cr[n];
    }
    if (n > 1)
    {
        if (r.back().fst == n)
            r.back().snd++;
        else
            r.pb({n, 1});
    }

    return r;
}

void div_rec(vector<ll> &r, vector<pair<ll, ll>> &f, ll k, ll c)
{
    if (k == (ll)f.size())
    {
        r.pb(c);
        return;
    }
    fori(i, 0, f[k].snd + 1) div_rec(r, f, k + 1, c), c *= f[k].fst;
}
vector<ll> divisors(vector<pair<ll, ll>> f)
{
    vector<ll> r; // returns divisors given factorization
    div_rec(r, f, 0, 1);
    return r;
}
