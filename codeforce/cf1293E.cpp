#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
const int MXV = 3005;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<int> G[MXV];
LL par[MXV][MXV], sub[MXV][MXV], dp[MXV][MXV];

void dfs(int u, int root)
{
    sub[root][u] = 1;
    for(auto v: G[u])
    {
        if(v == par[root][u])
        {
            continue;
        }
        par[root][v] = u;
        dfs(v, root);
        sub[root][u] += sub[root][v];
    }
}

LL getDp(int u, int v)
{
    if(u == v)
    {
        return 0;
    }
    if(dp[u][v] != -1)
    {
        return dp[u][v];
    }
    dp[u][v] =
        sub[u][v] * sub[v][u] + max(getDp(v, par[v][u]), getDp(par[u][v], u));
    return dp[u][v];
}

int main()
{
    IOS;
    int n;
    cin >> n;
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
    {
        dfs(i, i);
    }
    LL ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ans = max(ans, getDp(i, j));
        }
    }
    cout << ans << '\n';
}