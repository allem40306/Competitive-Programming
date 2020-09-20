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

int main()
{
    // IOS;
    int n;
    cin >> n;
    VVI data(3, VI(n + 5)), dp(3, VI(n + 5));
    FOR(i, 0, n) { cin >> data[0][i] >> data[1][i] >> data[2][i]; }
    FOR(i, 0, 3)
    {
        fill(dp[i].begin(), dp[i].end(), 0);
        dp[i][0] = data[i][0];
    }

    FOR(i, 1, n) FOR(j, 0, 3)
    {
        FOR(k, 0, 3) if (j != k)
        {
            dp[j][i] = max(dp[j][i], dp[k][i - 1] + data[j][i]);
        }
        // printf("%d,%d=%d\n", j, i, dp[j][i]);
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
}
