pair<vi, map<ll, ll>> compress(vi &a)
{
    vi inv = a;
    sort(all(inv));
    inv.erase(unique(all(inv)), inv.end());

    map<ll, ll> rank;
    fori(i, 0, SZ(inv))
        rank[inv[i]] = i;

    for (auto &x : a)
        x = rank[x];

    return {inv, rank};
}

// test: https://codeforces.com/gym/102951/submission/228361925
