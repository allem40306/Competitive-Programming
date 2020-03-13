/*
source: ABC 157 D Friend Suggestions
*/
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
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return;
        }
        if (sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
    }
    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }
    int getSize(int u)
    {
        u = find(u);
        return sz[u];
    }
};

int main()
{
    IOS;
    DisjointSet djs;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n + 1, 0);
    djs.init(n);
    FOR(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        --ans[x];
        --ans[y];
        djs.Union(x, y);
    }
    FOR(i, 0, k)
    {
        int x, y;
        cin >> x >> y;
        if (djs.isSame(x, y))
        {
            --ans[x];
            --ans[y];
        }
    }
    // FOR(i, 1, n + 1) { cout << ans[i] << " \n"[i == n]; }
    FOR(i, 1, n + 1) { cout << ans[i] + djs.getSize(i) - 1 << " \n"[i == n]; }
}
