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
const int MXN = 1e2 + 5;
const int MXK = 1e5 + 5;
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
vector<int> v(MXN);
int dp[MXN][MXK], sum[MXN][MXK];

int main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    dp[0][k] = sum[0][k] = 1;
    FOR(i, 1, n + 1)
    {
        int x;
        cin >> x;
        FOR(j, 1, k + 1)
        {
            dp[i][j] =
                (sum[i - 1][min(k, j + x)] - sum[i - 1][j - 1] + MOD) % MOD;
        }
        dp[i][0] = sum[i][0] = sum[i - 1][x];
        FOR(j, 1, k + 1) { sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD; }
    }
    cout << dp[n][0] << '\n';
}
