#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int M = 2e3;
const int MXV = 1e3 + 5;
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
vector<int> G[MXV];
int dp[MXV][2];
bitset<MXV> vis;

void init(int n, int m)
{
    FOR(i, 0, n + 1) { G[i].clear(); }
    FOR(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vis.reset();
}

void dfs(int u)
{
    vis[u] = true;
    dp[u][0] = 0;
    dp[u][1] = M;

    for(int v: G[u])
    {
        if(vis[v])
        {
            continue;
        }
        dfs(v);
        dp[u][0] += dp[v][1] + 1;
        if(dp[v][0] < dp[v][1])
        {
            dp[u][1] += dp[v][0] + 1;
        }
        else
        {
            dp[u][1] += dp[v][1];
        }
    }

    return ;
}

int main()
{
    IOS;
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init(n, m);
        int ans = 0;
        FOR(i,0,n)
        {
            if(!vis[i])
            {
                dfs(i);
                ans += min(dp[i][0], dp[i][1]);
            }
        }
        cout << ans / M << ' ' << m - ans % M << ' ' << ans % M << '\n';
    }
}
