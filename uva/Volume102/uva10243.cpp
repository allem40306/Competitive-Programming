#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
vector<int> G[N];
bitset<N> vis;
int dp[N][N];

void add_Edge(int x, int y) { G[x].push_back(y); }

void init(int n)
{
    for (int i = 0; i <= n; i++)
        G[i].clear();
    for (int i = 1, j, t; i <= n; i++)
    {
        cin >> t;
        while (t--)
        {
            cin >> j;
            add_Edge(i, j);
        }
    }
}

void dfs(int s)
{
    vis[s] = 1;
    dp[s][0] = 0;
    dp[s][1] = 1;
    for (int it : G[s])
    {
        if (vis[it])
            continue;
        dfs(it);
        dp[s][0] += dp[it][1];
        dp[s][1] += min(dp[it][0], dp[it][1]);
    }
}

void sol(int n)
{
    static int ans;
    ans = 0;
    vis.reset();
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        ans += min(dp[i][0], dp[i][1]);
    }
    cout << ans << '\n';
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        init(n);
        if (n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        sol(n);
    }
}