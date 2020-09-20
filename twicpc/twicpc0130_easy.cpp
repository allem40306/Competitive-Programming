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
const int MXV = 15;
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
int n, m;
int G[MXV][MXV];
int ans = 0;
bitset<MXV> vis;
vector<int> tmp(10);

void dfs(int u, int sz, int first)
{
    FOR(v, first, n + 1) if (G[u][v])
    {
        if (v == first)
        {
            if (sz >= 2)
            {
                ++ans;
            }
        }
        else if (!vis[v])
        {
            vis[v] = true;
            dfs(v, sz + 1, first);
            vis[v] = false;
        }
    }
}

int main()
{
    IOS;
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        G[x][y] = G[y][x] = 1;
    }
    FOR(i, 1, n + 1) { dfs(i, 0, i); }
    cout << ans / 2 << '\n';
}
