#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 300;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e6;
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

int main()
{
    // IOS;
    for (int i = 0; i < MXN; ++i)
        dp[i][0] = 1;
    for (int i = 1; i < MXN; ++i)
        for (int j = 1; j < MXN; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    int n, k;
    while (cin >> n >> k, n || k)
        cout << dp[n + k - 1][k - 1] << '\n';
}