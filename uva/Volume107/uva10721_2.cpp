#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 55;
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
LL dp[MXN][MXN][MXN];

int main()
{
    IOS;
    FOR(i, 0, MXN) dp[0][0][i] = 1;
    FOR(i, 1, MXN) FOR(j, 1, MXN) FOR(k, 1, MXN)
    {
        for (int x = 1; x <= i && x <= k; ++x)
            dp[i][j][k] += dp[i - x][j - 1][k];
    }
    int n, k, m;
    while (cin >> n >> k >> m)
        cout << dp[n][k][m] << '\n';
}
