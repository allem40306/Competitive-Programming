#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 1e5 + 5;
const int LOG = 20;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
vector<int> G[MXV];
int n;
int par[MXV][LOG];
int tin[MXV], tout[MXV], dist[MXV];
int timer = 0;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    par[v][0] = p;
    if (v != p)
        dist[v] = dist[p] + 1;
    for (int it : G[v])
    {
        if (it != p)
            dfs(it, v);
    }
    tout[v] = ++timer;
}

void Doubling()
{
    for (int i = 1; i <= LOG; ++i)
        for (int j = 1; j <= n; ++j)
            par[j][i] = par[par[j][i - 1]][i - 1];
}

bool anc(int v, int u) { return tin[v] <= tin[u] && tout[u] <= tout[v]; }

int LCA(int v, int u)
{
    if (anc(v, u))
        return v;
    for (int j = LOG - 1; j >= 0; --j)
    {
        if (!anc(par[v][j], u))
            v = par[v][j];
    }
    return par[v][0];
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dist[1] = 1;
    dfs(1, 1);
    Doubling();
    for (int i = 0, u, v; i < q; ++i)
    {
        cin >> u >> v;
        int w = LCA(v, u);
        int res = (dist[u] + dist[v] - 2 * dist[w]) % 2;
        if (res)
            cout << "Road\n";
        else
            cout << "Town\n";
    }
}
