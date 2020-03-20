#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 55;
const int MXM = 2e4 + 5;
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

int sum[MXN][MXM], dp[MXN][MXM], Lmax[MXN][MXM], Rmax[MXN][MXM];

int getSum(int x, int L, int R) { return sum[x][R] - sum[x][L - 1]; }

int main()
{
    IOS;
    int n, m, k;
    cin >> n >> m >> k;
    FOR(i, 1, n + 1) FOR(j, 1, m + 1)
    {
        cin >> sum[i][j];
        sum[i][j] = sum[i][j - 1] + sum[i][j];
    }
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m - k + 2)
        {
            int ksum = getSum(i, j, j + k - 1) + getSum(i + 1, j, j + k - 1);
            if (i == 1)
            {
                dp[i][j] = ksum;
                continue;
            }
            FOR(x, max(1, j - k + 1), min(j + k - 1, m - k + 1) + 1)
            {
                int overlapSum =
                    getSum(i, max(j, x), min(j + k - 1, x + k - 1));
                dp[i][j] = max(dp[i][j], dp[i - 1][x] + ksum - overlapSum);
            }
            if (j - k > 0)
            {
                dp[i][j] = max(dp[i][j], ksum + Lmax[i - 1][j - k]);
            }
            if (j + k <= m)
            {
                dp[i][j] = max(dp[i][j], ksum + Rmax[i - 1][j + k]);
            }
        }
        FOR(j, 1, m - k + 2) { Lmax[i][j] = max(Lmax[i][j - 1], dp[i][j]); }
        FORD(j, m - k + 1, 0) { Rmax[i][j] = max(Rmax[i][j + 1], dp[i][j]); }
    }
    int ans = 0;
    FOR(i, 1, m - k + 2) { ans = max(ans, dp[n][i]); }
    cout << ans << '\n';
}
