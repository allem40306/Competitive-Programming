/*
source: AtCoder Beginner Contest 155 F
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const LL INF = 1e18;
const int MXN = 100005;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define Fi first
#define Se second
#define Be begin()
#define En end()
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

bitset<MXN> vis;
vector<int> ans, x;
vector<PII> G[MXN + 1];

int dfs(int u)
{
    vis[u] = true;
    int res = x[u];
    for (auto it : G[u])
    {
        if (!vis[it.Fi])
        {
            int tmp = dfs(it.Fi);
            if (tmp != 0)
            {
                ans.PB(it.Se);
            }
            res ^= tmp;
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<PII> bombs(n);
    x.resize(n + 1);
    FOR(i, 0, n) { cin >> bombs[i].Fi >> bombs[i].Se; }
    sort(bombs.Be, bombs.En);
    x[0] = bombs[0].Se;
    FOR(i, 0, n - 1) { x[i + 1] = bombs[i].Se ^ bombs[i + 1].Se; }
    x[n] = bombs[n - 1].Se;

    FOR(i, 0, m)
    {
        int L, R;
        cin >> L >> R;
        L = lower_bound(bombs.Be, bombs.En, PII{L, 0}) - bombs.Be;
        R = upper_bound(bombs.Be, bombs.En, PII{R, 1}) - bombs.Be;
        G[L].EB(R, i + 1);
        G[R].EB(L, i + 1);
    }
    vis.reset();
    FOR(i, 0, n + 1)
    {
        if (vis[i])
        {
            continue;
        }
        if (dfs(i))
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans.size() << '\n';
    sort(ans.Be, ans.En);
    FOR(i, 0, ans.size()) { cout << ans[i] << " \n"[i == (int)ans.size() - 1]; }
}
