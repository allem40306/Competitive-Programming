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
const int MXV = 1e4 + 5;
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
int ans = 0;
vector<int> G[MXV], p(MXV);
bitset<MXV> vis;

void dfs(int u, int dep)
{
    ans = max(ans, dep);
    vis[u] = true;
    for (int v : G[u])
    {
        if (!vis[v])
        {
            dfs(v, dep + 1);
        }
    }
}

int main()
{
    IOS;
    int n;
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> p[i];
        if (p[i] != -1)
        {
            G[p[i]].push_back(i);
        }
    }
    vis.reset();
    ans = 0;
    FOR(i, 1, n + 1) if (p[i] == -1) { dfs(i, 1); }
    cout << ans << '\n';
}
