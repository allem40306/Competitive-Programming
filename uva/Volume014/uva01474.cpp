#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const LL INF = 1e18;
const int MXN = 5e3;
const int MXV = 0;
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
struct Loc
{
    int id, p; // p(ostion)
} t[MXN], s[MXN];
LL dp[2][MXN];
int path[MXN][MXN], sel[MXN]; // sel(ection)

void dfs(int x, int y)
{
    if (x == 0 || y == 0)
        return;
    sel[t[x].id] = s[y].id;
    dfs(x - 1, y - path[x][y]);
}

int main()
{
    IOS;
    int n, m;
    while (cin >> n)
    {
        FOR(i, 1, n + 1)
        {
            t[i].id = i;
            cin >> t[i].p;
        }
        cin >> m;
        FOR(i, 1, m + 1)
        {
            s[i].id = i;
            cin >> s[i].p;
        }
        sort(t + 1, t + n + 1, [](Loc a, Loc b) { return a.p < b.p; });
        sort(s + 1, s + m + 1, [](Loc a, Loc b) { return a.p < b.p; });

        memset(dp, 0x3f, sizeof(dp));
        FOR(j, 0, n + 1) dp[0][j] = INF;
        dp[0][0] = 0;
        FOR(i, 1, n + 1)
        {
            int cur = i & 1, lst = 1 - cur;
            FOR(j, 0, m + 1) dp[cur][j] = INF; // meed to init dp[cur][0]
            FOR(j, 1, min(i, m) + 1)
            {
                if (dp[lst][j - 1] < dp[lst][j])
                {
                    dp[cur][j] = dp[lst][j - 1] + abs(t[i].p - s[j].p);
                    path[i][j] = 1;
                }
                else
                {
                    dp[cur][j] = dp[lst][j] + abs(t[i].p - s[j].p);
                    path[i][j] = 0;
                }
            }
        }
        LL ans = dp[n & 1][m];
        dfs(n, m);
        cout << ans << '\n';
        FOR(i, 1, n + 1) cout << sel[i] << " \n"[i == n];
    }
}
