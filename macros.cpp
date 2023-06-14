#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define fst first
#define snd second
#define fori(i, a, b) for (ll i = a; i < (ll)b; i++)
#define rof(i, a, b) for (ll i = a - 1; i >= b; i--)
#define fore(xs, x) for (auto x : xs)
#define forp(xs, a, b) for (auto [a, b] : xs)
#define prnt(x) cout << (x) << "\n"
#define all(x) begin(x), end(x)
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vld vector<ld>
#define vvld vector<vector<ld>>
#define vc vector<char>
#define vvc vector<vector<char>>
using namespace std;
const ll dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const ll INF = 1e18;
const ll MAXN = 21;
const ll K = 63 - __builtin_clzll(MAXN) + 1;
const ll MOD = 1e9 + 1;
