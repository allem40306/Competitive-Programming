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
vector<int> dp(MXV, 0), din(MXV, 0);
vector<int> G[MXV];

int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int f, t;
        cin >> f >> t;
        G[f].PB(t);
        ++din[t];
    }
    deque<int> q;
    FOR(i, 1, n + 1) if (din[i] == 0) { q.push_back(i); }
    int ans = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        ans = max(ans, dp[u]);
        for (int v : G[u])
        {
            if (dp[v] < dp[u] + 1)
            {
                dp[v] = dp[u] + 1;
            }
            --din[v];
            if (din[v] == 0)
            {
                q.push_back(v);
            }
        }
    }
    cout << ans << '\n';
}
