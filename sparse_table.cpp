#define oper min
vvll st(K, vll(1 << K));
void st_init(vll &a)
{
    fori(i, 0, n) st[0][i] = a[i];

    fori(k, 1, K) fori(i, 0, n - (1 << k) + 1)
        st[k][i] = oper(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}

ll st_query(int s, int e) // [s, e)
{
    int k = 31 - __builtin_clz(e - s);
    return oper(st[k][s], st[k][e - (1 << k)]);
}
