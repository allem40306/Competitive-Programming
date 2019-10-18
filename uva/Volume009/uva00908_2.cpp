#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
const int MXV = 1000005;

struct Edge
{
    int from, to, w;
    bool operator<(const Edge &rhs) // optional
    {
        return w < rhs.w;
    }
};

struct DisjointSet
{
    int p[MXV], sz[MXV];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return false;
        }
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
        return true;
    }
};

int main()
{
    IOS;
    int n, m, k, ti = 0;
    static DisjointSet djs;
    while (cin >> n)
    {
        if (ti++)
        {
            cout << '\n';
        }
        vector<Edge> edges;
        int ans1 = 0, ans2 = 0;
        for (int i = 0, from, to, w; i < n - 1; i++)
        {
            cin >> from >> to >> w;
            ans1 += w;
        }
        cin >> k;
        for (int i = 0, from, to, w; i < k; i++)
        {
            cin >> from >> to >> w;
            edges.push_back({from, to, w});
        }
        cin >> m;
        for (int i = 0, from, to, w; i < m; i++)
        {
            cin >> from >> to >> w;
            edges.push_back({from, to, w});
        }
        sort(edges.begin(), edges.end());
        djs.init(n);
        for (auto edge : edges)
        {
            if (djs.Union(edge.from, edge.to))
            {
                ans2 += edge.w;
            }
        }
        cout << ans1 << endl << ans2 << endl;
    }
}