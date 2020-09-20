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
const int MXN = 3e3 + 5;
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
double dp[MXN][MXN];

int main()
{
    IOS;
    int n;
    cin >> n;
    dp[0][0] = 1;
    FOR(i, 1, n + 1)
    {
        double x;
        cin >> x;
        FOR(j, 0, n + 1)
        {
            dp[i][j] += (1 - x) * dp[i - 1][j];
            if (j)
            {
                dp[i][j] += x * dp[i - 1][j - 1];
            }
        }
    }
    double ans = 0;
    FORD(i, n, n / 2) { ans += dp[n][i]; }
    cout << fixed << setprecision(10) << ans << '\n';
}
