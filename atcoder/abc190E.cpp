#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e8;
const int MXK = 20;
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
vector<int> G[MXV];
int dis[MXV];
queue<int> q;

void bfs(int s)
{
    while (!q.empty())
        q.pop();
    FOR(i, 0, MXV) dis[i] = INF;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int v : G[cur])
            if (dis[v] == INF)
            {
                dis[v] = dis[cur] + 1;
                q.push(v);
            }
    }
    return;
}

int k, c[MXK], dist[MXK][MXK], dp[(1 << MXK)][MXK];

int dfs(int s, int tail)
{
    if (s == (1 << k) - 1)
        return 0;
    int &ret = dp[s][tail];
    if (ret != INF)
        return ret;
    FOR(i, 0, k)
    {
        if ((s & (1 << i)))
            continue;
        ret = min(ret, dfs(s | (1 << i), i) + dist[i][tail]);
    }
    return ret;
}

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i)
    {
        cin >> x >> y;
        G[x].PB(y);
        G[y].PB(x);
    }
    cin >> k;
    FOR(i, 0, k) cin >> c[i];
    FOR(i, 0, k)
    {
        bfs(c[i]);
        FOR(j, 0, k) { dist[i][j] = dist[j][i] = dis[c[j]]; }
    }
    int ans = INF;
    FOR(i, 0, (1 << MXK)) FOR(j, 0, k) dp[i][j] = INF;
    for (int i = 0; i < k; i++)
        if (dist[0][i] == INF)
        {
            cout << "-1\n";
            return 0;
        }
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, 1 + dfs((1 << i), i));
    }
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}
