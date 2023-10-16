vvii g(MAXN);
vi d(MAXN, INF);
vi p(MAXN);
ll n, m;

void dijkstra(ll s) // O(n^2 + m)
{
    vector<bool> u(n);
    d[s] = 0;

    fori(i, 0, n)
    {
        ll v = -1;
        fori(j, 0, n) if (!u[j] && (v == -1 || d[j] < d[v]))
            v = j;

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : g[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

void dijkstra(ll s) // O(m log n)
{
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : g[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
 
vi get_path(ll s, ll e)
{
    vi path;
 
    for (ll v = e; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
 
    reverse(all(path));
    return path;
}
