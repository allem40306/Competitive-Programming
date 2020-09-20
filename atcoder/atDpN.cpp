#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const LL INF = 1e18;
const int MXN = 5e2;
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

int t, ti, n;
long long arr[MXN], dp[MXN][MXN];

int main()
{
    IOS;
    cin >> n;
    arr[0] = 0;
    FOR(i, 0, MXN) FOR(j, 0, MXN) { dp[i][j] = INF; }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = 0;
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            for (int k = j; k < i + j; k++)
            {
                dp[j][i + j] = min((j != k) * dp[j][k] +
                                       (k + 1 != i + j) * dp[k + 1][i + j] +
                                       arr[i + j] - arr[j - 1],
                                   dp[j][i + j]);
            }
        }
    }
    cout << dp[1][n] << '\n';
}
