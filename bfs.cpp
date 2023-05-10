vector<vector<ll>> adj;  // adjacency list representation
ll n; // number of nodes

vector<bool> used(n);
vector<ll> d(n), p(n);

void bfs(ll s) {
  queue<int> q;
  q.push(s);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : adj[v]) {
          if (!used[u]) {
              used[u] = true;
              q.push(u);
              d[u] = d[v] + 1;
              p[u] = v;
          }
      }
  }
}
