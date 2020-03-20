#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 1e5 + 5;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

const int LOG = 20;
vector<int> tin(MXV), tout(MXV), depth(MXV);
int par[MXV][LOG];
int timer = 0;
vector<int> G[MXV];

void dfs(int u, int f)
{
    tin[u] = ++timer;
    par[u][0] = f;
    for (int v : G[u])
    {
        if (v != f)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

void Doubling(int n)
{
    for (int j = 1; j < LOG; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

bool anc(int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; }

int LCA(int u, int v)
{
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    if (anc(u, v))
    {
        return u;
    }
    for (int j = LOG - 1; j >= 0; --j)
    {
        if (!anc(par[u][j], v))
            u = par[u][j];
    }
    return par[u][0];
}

int dis(int u, int v)
{
    int lca = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main()
{
    IOS;
    int n;
    cin >> n;
    FOR(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root = 1;
    depth[root] = 0;
    dfs(root, root);
    Doubling(n);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int w[3];
        w[0] = k - dis(a, b);
        w[1] = k - (dis(a, x) + dis(y, b) + 1);
        w[2] = k - (dis(a, y) + dis(x, b) + 1);
        bool ok = false;
        FOR(i, 0, 3)
        {
            if (w[i] >= 0 && w[i] % 2 == 0)
            {
                ok = true;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
