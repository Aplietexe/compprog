struct PathQueries {  // O(n log n) preprocessing, O(log n) query
  typedef ll T;
  constexpr static T NEUT = -1e18;
  T op(const T &a, const T &b) { return max(a, b); }  // associative and commutative
  ll n, K;
  vector<vi> &g;  // remove & for edge queries or if instance lives longer
  vector<vi> anc;
  vector<vector<T>> part;
  vi dep;
  // NODES
  PathQueries(vector<vi> &_g, vector<T> &vals) : n(SZ(_g)), K(64 - __builtin_clzll(n)), g(_g), anc(K, vi(n)), part(K, vector<T>(n, NEUT)), dep(n) {
    anc[0][0] = -1, dfs(0);
    part[0] = vals;
    init();
  }
  // EDGES
  // PathQueries(vector<vector<pair<ll, T>>> &_g) : n(SZ(_g)), K(64 - __builtin_clzll(n)), g(n), anc(K, vi(n)), part(K, vector<T>(n, NEUT)), dep(n) {
  //   fore(u, 0, n) for (auto [v, data] : _g[u]) g[u].pb(v);
  //   anc[0][0] = -1, dfs(0);
  //   fore(u, 0, n) for (auto [v, data] : _g[u]) part[0][dep[u] > dep[v] ? u : v] = data;
  //   init();
  // }
  void init() {
    fore(k, 1, K) fore(v, 0, n) if (anc[k - 1][v] != -1) {
      anc[k][v] = anc[k - 1][anc[k - 1][v]];
      part[k][v] = op(part[k - 1][v], part[k - 1][anc[k - 1][v]]);
    }
    else anc[k][v] = -1;
  }
  void dfs(ll u) {
    for (ll v : g[u]) {
      if (v == anc[0][u]) continue;
      anc[0][v] = u, dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
  T query(ll u, ll v) {
    if (dep[u] < dep[v]) swap(u, v);
    T ans = NEUT;
    for (ll k = K - 1; k >= 0; --k)
      if (dep[u] - (1 << k) >= dep[v]) ans = op(ans, part[k][u]), u = anc[k][u];
    if (u == v)
      // return ans; // edge queries
      return op(ans, part[0][u]);  // node queries
    for (ll k = K - 1; k >= 0; --k)
      if (anc[k][u] != anc[k][v]) ans = op(ans, op(part[k][u], part[k][v])), u = anc[k][u], v = anc[k][v];
    ans = op(ans, op(part[0][u], part[0][v]));
    // return ans; // edge queries
    return op(ans, part[0][anc[0][u]]);  // node queries
  }
};
