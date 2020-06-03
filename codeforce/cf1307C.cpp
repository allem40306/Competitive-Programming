#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<LL>;
using VVI = vector<VI>;
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

int main()
{
    IOS;
    string s;
    cin >> s;
    int n = (int)s.size();
    VI dp(30, 0);
    VVI dp2(30, VI(30, 0));
    FOR(i, 0, n)
    {
        int no = (int)(s[i] - 'a');
        FOR(j, 0, 30) { dp2[j][no] += dp[j]; }
        ++dp[no];
    }
    LL ans = 0;
    FOR(i, 0, 30)
    {
        FOR(j, 0, 30) { ans = max(ans, dp2[i][j]); }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}
