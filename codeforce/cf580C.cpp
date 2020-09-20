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
const int MXV = 1e5 + 5;
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
int m, ans;
vector<int> G[MXV], a(MXV);
bitset<MXV> vis;

void dfs(int u, int cnt)
{
    cnt = (a[u] ? cnt + 1 : 0);
    if (cnt > m)
    {
        return;
    }
    vis[u] = true;
    bool leaf = true;
    for (int v : G[u])
    {
        if (!vis[v])
        {
            leaf = false;
            dfs(v, cnt);
        }
    }
    if (leaf)
    {
        ++ans;
    }
}

int main()
{
    IOS;
    int n;
    cin >> n >> m;
    FOR(i, 1, n + 1) { cin >> a[i]; }
    FOR(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vis.reset();
    ans = 0;
    dfs(1, 0);
    cout << ans << '\n';
}
