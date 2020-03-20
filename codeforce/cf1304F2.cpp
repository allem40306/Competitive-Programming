#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<VI>;
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

int n, m, k;
VVI init(MXN, VI(MXM, 0));
VVI a, rev_a, sum, rev_sum, Lmax, Rmax, dp, dpL, dpR;

int getSum(VVI &sum, int x, int L, int R)
{
    if (L < 1)
    {
        return sum[x][R];
    }
    return sum[x][R] - sum[x][L - 1];
}

void calc_overlapped(VVI &sum, VVI &dp, int i)
{
    deque<PII> dq;
    FOR(j, 1, m - k + 2)
    {
        int num = dp[i - 1][j] - getSum(sum, i, j, j + k - 1);
        while (!dq.empty() && dq.front().S <= j - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() &&
               dq.back().F + getSum(sum, i, dq.back().S, j - 1) <= num)
        {
            dq.pop_back();
        }
        dq.push_back({num, j});
        dp[i][j] = dq.front().F + getSum(sum, i, dq.front().S, j - 1) +
                   getSum(sum, i, j, j + k - 1) +
                   getSum(sum, i + 1, j, j + k - 1);
    }
}

int main()
{
    IOS;
    cin >> n >> m >> k;
    a = rev_a = sum = rev_sum = Lmax = Rmax = dp = dpL = dpR = init;
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m + 1)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
        FOR(j, 1, m + 1)
        {
            rev_a[i][j] = a[i][m - j + 1];
            rev_sum[i][j] = rev_sum[i][j - 1] + rev_a[i][j];
        }
    }
    FOR(i, 1, n + 1)
    {
        FOR(j, 1, m - k + 2)
        {
            int ksum =
                getSum(sum, i, j, j + k - 1) + getSum(sum, i + 1, j, j + k - 1);
            dp[i][j] = ksum;
            if (j - k > 0)
            {
                dp[i][j] = max(dp[i][j], ksum + Lmax[i - 1][j - k]);
            }
            if (j + k <= m - k + 1)
            {
                dp[i][j] = max(dp[i][j], ksum + Rmax[i - 1][j + k]);
            }
        }

        calc_overlapped(sum, dpL, i);
        calc_overlapped(rev_sum, dpR, i);

        FOR(j, 1, m - k + 2)
        {
            // m - k - j + 2 = (m - k + 1) - j + 1
            dp[i][j] = max({dp[i][j], dpL[i][j], dpR[i][m - k - j + 2]});
            dpL[i][j] = dpR[i][m - k - j + 2] = dp[i][j];
        }

        FOR(j, 1, m - k + 2) { Lmax[i][j] = max(Lmax[i][j - 1], dp[i][j]); }
        FORD(j, m - k + 1, 0) { Rmax[i][j] = max(Rmax[i][j + 1], dp[i][j]); }
    }
    int ans = 0;
    FOR(i, 1, m - k + 2) { ans = max(ans, dp[n][i]); }
    cout << ans << '\n';
}
