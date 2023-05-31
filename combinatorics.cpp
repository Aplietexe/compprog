vll fact(MAXN + 1);
vll inv_fact(MAXN + 1);
void calc_fact(ll a)
{
    fact[0] = 1;
    inv_fact[0] = 1;
    fori(i, 1, a + 1)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = moddiv(1, fact[i]);
    }
}

ll n_choose_k(ll n, ll k) // requires fact[n]
{
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
    // return moddiv(fact[n], fact[k] * fact[n - k] % MOD);
}
