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
int dp[MXN][MXN];
string s[MXN];
int main()
{
    IOS;
    int h, w;
    cin >> h >> w;
    dp[0][0] = 1;
    FOR(i, 0, h) { cin >> s[i]; }
    FOR(i, 0, h)
    {
        dp[i][0] = ((!i || (s[i][0] == '.' && dp[i - 1][0])) ? 1 : 0);
    }
    FOR(j, 0, w)
    {
        dp[0][j] = ((!j || (s[0][j] == '.' && dp[0][j - 1])) ? 1 : 0);
    }
    FOR(i, 1, h) FOR(j, 1, w)
    {
        if (s[i][j] == '.')
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[h - 1][w - 1] << '\n';
}
