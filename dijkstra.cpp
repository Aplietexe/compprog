vector<vector<pair<ll, ll>>> g(MAXN);
vll d(MAXN, -1);
vll p(MAXN);
ll n, m;
 
void dijkstra(ll v)
{
    d[v] = 0;
 
    priority_queue<pair<ll, ll>> q;
    q.push({0, v});
 
    while (!q.empty())
    {
        v = q.top().snd;
        ll c = -q.top().fst;
        q.pop();
 
        if (d[v] != c)
            continue;
 
        fori(i, 0, g[v].size())
        {
            ll to = g[v][i].fst;
            ll c = g[v][i].snd;
            if (d[to] < 0 || d[v] + c < d[to])
            {
                d[to] = d[v] + c;
                p[to] = v;
                q.push({-d[to], to});
            }
        }
    }
}
 
vector<ll> get_path(ll s, ll e)
{
    vector<ll> path;
 
    for (ll v = e; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
 
    reverse(all(path));
    return path;
}
