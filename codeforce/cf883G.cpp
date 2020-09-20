#pragma GCC optimize("O2")
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
const int MXV = 3e5 + 5;
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
struct Edge
{
    int f, t, dir, isDir;
};
vector<int> G[MXV], p(MXV);
vector<Edge> edges1, edges2;
bitset<MXV> vis;

void dfs1(vector<Edge> &edges, int &ans, int u, int isMin)
{
    // cout << '*' << u << '\n';
    ++ans;
    vis[u] = true;

    for (int i : G[u])
    {
        Edge &e = edges[i];
        // cout << i << ' ' << e.f << ' ' << e.t << '\n';
        int v = u ^ e.f ^ e.t;
        if (vis[v])
        {
            continue;
        }
        if (e.dir == -1)
        {
            e.dir = (e.f != u) ^ isMin;
        }
        // cout << v << ' ' << e.dir << '\n';
        if ((e.dir == 0 && u == e.f) || (e.dir == 1 && u == e.t))
        {
            dfs1(edges, ans, v, isMin);
        }
    }
}

int main()
{
    IOS;
    int n, m, s, ans;
    cin >> n >> m >> s;
    FOR(i, 0, m)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 2)
        {
            G[u].push_back(i);
            G[v].push_back(i);
            edges1.push_back({u, v, -1, 0});
        }
        else
        {
            G[u].push_back(i);
            edges1.push_back({u, v, 0, 1});
        }
    }
    edges2 = edges1;
    
    vis.reset();
    ans = 0;
    dfs1(edges1, ans, s, 0);
    cout << ans << '\n';
    FOR(i, 0, m)
    {
        if (!edges1[i].isDir)
            cout << "+-"[edges1[i].dir == 1];
    }
    cout << '\n';

    vis.reset();
    ans = 0;
    dfs1(edges2, ans, s, 1);
    cout << ans << '\n';
    FOR(i, 0, m)
    {
        if (!edges2[i].isDir)
            cout << "+-"[edges2[i].dir == 1];
    }
    cout << '\n';
}
