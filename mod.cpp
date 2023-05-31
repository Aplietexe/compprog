ll modpow(ll b, ll e)
{
    ll res = 1;
    while (e > 0)
    {
        if (e & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

ll moddiv(ll a, ll b)
{
    return a * modpow(b, MOD - 2) % MOD;
}

ll sum(ll s, ll e)
{
    ll n = ((s + e) % MOD) * ((e - s + 1) % MOD);
    return moddiv(n % MOD, 2);
}
