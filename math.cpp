bool is_prime(ll n) // O(sqrt(n))
{
    if (n % 2 == 0)
        return n == 2;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return n >= 2;
}

vi divisors(ll n) // O(sqrt(n))
{
    vi res;

    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            res.pb(i);
            if (i != n / i)
                res.pb(n / i);
        }

    return res;
}

vii p_factors(ll n) // O(sqrt(n))
{
    vii res;

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

vi lp(MAXN + 1), pr; // 0 if 0, 1 or prime. The smallest prime divisor otherwise
void linear_sieve()  // O(n)
{
    fori(i, 0, MAXN + 1)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= MAXN; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
                break;
        }
    }
}

vii sieve_fact(int n)
{
    if (n == 1)
        return {};
    if (lp[n] == -1)
        return {{n, 1}};
    vii r;
    ll last = 0;
    while (lp[n] >= 0)
    {
        if (lp[n] != last)
            r.pb({lp[n], 0}), last = lp[n];
        r.back().snd++;
        n /= lp[n];
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

void div_rec(vi &r, vii &f, ll k, ll c)
{
    if (k == (ll)f.size())
    {
        r.pb(c);
        return;
    }
    fori(i, 0, f[k].snd + 1) div_rec(r, f, k + 1, c), c *= f[k].fst;
}
vi divisors(vii f)
{
    vi r; // returns divisors given factorization
    div_rec(r, f, 0, 1);
    return r;
}

ll S_k(ll first, ll last, ll step) // sum(range(first, last, step))
{
    if (first >= last)
        return 0;

    last--;
    ll k = (last - first) / step + 1;
    ll a_k = first + (k - 1) * step;
    return (k * (first + a_k)) / 2;
}

ll modpow(ll b, ll e)
{
    ll ans = 1;
    for (; e; b = b * b % MOD, e /= 2)
        if (e & 1)
            ans = ans * b % MOD;
    return ans;
}

ll moddiv(ll a, ll b)
{
    return a * modpow(b, MOD - 2) % MOD;
}

ll S_k(ll first, ll last, ll step) // sum(range(first, last, step)) % MOD
{
    if (first >= last)
        return 0;

    last--;
    ll k = (last - first) / step + 1;
    ll a_k = (first + (k - 1) * step) % MOD;
    return moddiv(k * (first + a_k) % MOD, 2);
}
