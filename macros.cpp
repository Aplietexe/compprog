#include <bits/stdc++.h>
typedef long long ll;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define pb push_back
#define fst first
#define snd second
#define fori(i, a, b) for (ll i = a; i < (ll)b; i++)
#define rof(i, a, b) for (ll i = a - 1; i >= b; i--)
#define fore(x, xi) for (auto xi : x)
#define prnt(x) cout << (x) << "\n"
#define all(x) begin(x), end(x)
#define upper(x)      \
    for (char &c : x) \
    c = toupper(c)
#define lower(x)      \
    for (char &c : x) \
    c = tolower(c)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define dgrid(a, r, c, init) vvll a(c, vector<ll>(r, (init)))
#define vvc vector<vector<char>>
#define vtll vector<tuple<ll, ll, ll>>
#define dvvc(a, r, c) vvc a(c, vector<char>(r))
using namespace std;
const ll dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
const ll MAXN = 1e6 + 10;
