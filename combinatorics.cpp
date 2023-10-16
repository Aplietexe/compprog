vi fact;
vi inv_fact;
void init_fact(ll a)
{
    fact.resize(a + 1, 1);
    inv_fact.resize(a + 1, 1);
    fori(i, 2, a + 1)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = (MOD - MOD / i) * inv_fact[MOD % i] % MOD;
    }
    fori(i, 1, a + 1)
        inv_fact[i] = inv_fact[i - 1] * inv_fact[i] % MOD;
}

ll n_choose_k(ll n, ll k) // requires fact[n]
{
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
    // return moddiv(fact[n], fact[k] * fact[n - k] % MOD);
}

// test: https://cses.fi/problemset/result/7403121/
