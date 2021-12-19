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
const int MXV = 1005;
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
LL comb[MXV][MXV];
bitset<MXV> isRoot;

void build()
{
    FOR(i, 0, MXV) comb[i][0] = 1;
    FOR(i, 1, MXV)
    FOR(j, 1, i + 1) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
}

pair<LL, LL> dfs(int u)
{
    LL ans = 1, sz = 0;
    for (int v : G[u])
    {
        auto res = dfs(v);
        ans = ans * res.first % MOD;
        ans = ans * comb[sz + res.second][res.second] % MOD;
        // cout << sz << ' ' << res.second << ' ' << ans << '\n';
        sz += res.second;
    }
    // cout << u << ' ' << ans << ' ' << sz + 1 << '\n';
    return make_pair(ans, sz + 1);
}

int main()
{
    IOS;
    int t, n;
    cin >> t;
    build();
    FOR(ti, 1, t + 1)
    {
        FOR(i, 0, MXV) G[i].clear();
        isRoot.set();
        cin >> n;
        FOR(i, 1, n)
        {
            int x, y;
            cin >> x >> y;
            G[x].emplace_back(y);
            isRoot[y] = 0;
        }
        FOR(i, 1, n + 1)
        {
            if (!isRoot[i])
                continue;
            auto res = dfs(i);
            cout << "Case " << ti << ": " << res.first % MOD << '\n';
            break;
        }
    }
}
