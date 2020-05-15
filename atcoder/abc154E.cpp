/*
source: ABC 154 E Almost Everywhere Zero
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int dp[105][4][2];
// dp[i][j][k] i digit(s), j non-zero digit(s), k = 0 (= N), k = 1 (< N)

int main()
{
    IOS;
    string s;
    int n, K;
    cin >> s >> K;
    n = (int)s.size();
    dp[0][0][0] = 1;
    FOR(i, 0, n) FOR(j, 0, 4) FOR(k, 0, 2)
    {
        int nd = (s[i] - '0');
        FOR(d, 0, 10)
        {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0)
            {
                ++nj;
            }
            if (nj > K)
            {
                continue;
            }
            if(k == 0)
            {
                if(d > nd)
                {
                    continue;
                }
                if(d < nd)
                {
                    nk = 1;
                }
            }
            dp[ni][nj][nk] += dp[i][j][k];
            // cout << ni << ' ' << nj << ' ' << nk << ' ' << dp[ni][nj][nk] << '\n';
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << '\n';
}
