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
const int MXN = 1e3 + 5;
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
LL dp[MXN][5][2] = {}, ans[MXN] = {};

int main()
{
    // IOS;
    FOR(k, 0, 2)
    {
        dp[1][0][k] = 1;
        FOR(i, 2, MXN) FOR(j, 0, 5)
        {
            dp[i][j][k] = dp[i - 1][j][k];// +R
            if (j > 0)
            {
                dp[i][j][k] += dp[i - 1][j - 1][k]; // + OR
            }
            // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
        }
        FOR(i, 1, MXN)
        {
            if (i % 2 || i == 2)
            {
                continue;
            }
            int r = (i + 4) / 2;
            ans[i] = dp[r][4][0] + dp[r][4][1] + dp[r][3][0];
            // dp[r][4][0]: R....O
            // dp[r][4][1]: O....R
            // dp[r][3][0]: R....R
        }
    }
    int n, ti = 0;
    while (cin >> n, n)
    {
        cout << "Case " << ++ti << ": " << ans[n] << '\n';
    }
}
