#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const LL MOD = 998244353;
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
    IOS;
    int n, s;
    cin >> n >> s;
    vector<LL> a(n + 1, 0), dp(s + 1, 0);
    LL ans = 0;
    FOR(i, 1, n + 1) { cin >> a[i]; }
    FOR(i, 1, n + 1)
    {
        FORD(j, s, a[i] - 1) { dp[j] = (dp[j] + dp[j - a[i]]) % MOD; }
        if (a[i] <= s)
        {
            dp[a[i]] = (dp[a[i]] + i) % MOD;
        }
        ans = (ans + dp[s]) % MOD;
    }
    cout << ans << '\n';
}
