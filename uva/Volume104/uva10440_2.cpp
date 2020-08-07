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
    int c;
    vector<int> cars, dp[2];
    cin >> c;
    FOR(ci, 0, c)
    {
        int n, t, m;
        cin >> n >> t >> m;
        cars.resize(m + 1);
        dp[0].resize(m + 1);
        dp[1].resize(m + 1);
        fill(dp[0].begin(), dp[0].end(), INF);
        fill(dp[1].begin(), dp[1].end(), INF);
        FOR(i, 1, m + 1) { cin >> cars[i]; }
        dp[0][0] = -t;
        dp[1][0] = 0;
        dp[0][1] = cars[1] + t;
        dp[1][1] = 1;
        FOR(i, 2, m + 1)
        {
            FOR(j, max(0, i - n), i)
            {
                dp[0][i] = min(dp[0][i], max(dp[0][j] + 2 * t, cars[i] + t));
                dp[1][i] = min(dp[1][i], dp[1][j] + 1);
            }
        }
        cout << dp[0][m] << ' ' << dp[1][m] << '\n';
    }
}
