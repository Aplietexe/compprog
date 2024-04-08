auto compress(vi& a) {
    vi inv = a;
    sort(ALL(inv));
    inv.erase(unique(ALL(inv)), inv.end());
    auto rank = [inv](ll x) { return lower_bound(ALL(inv), x) - inv.begin(); };
    for (auto& x : a) x = rank(x);
    return pair(inv, rank);
}

// https://codeforces.com/gym/102951/submission/255777690
// https://codeforces.com/contest/1955/submission/255777078
