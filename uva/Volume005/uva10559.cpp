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
int c[MXN], pr[MXN], lst[MXN]; // pr(ev), ,l(a)st
int dp[MXN][MXN][MXN];

int dfs(int L, int R, int k)
{
    if (L > R)
        return 0;
    if (dp[L][R][k])
        return dp[L][R][k];
    int &res = dp[L][R][k];
    res = dfs(L, R - 1, 0) + (k + 1) * (k + 1);
    for (int i = pr[R]; i >= L; i = pr[i])
        res = max(res, dfs(L, i, k + 1) + dfs(i + 1, R - 1, 0));
    return res;
}

int main()
{
    IOS;
    int T;
    int n;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti)
    {
        memset(dp, 0, sizeof(dp));
        memset(lst, 0, sizeof(lst));
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> c[i];
            pr[i] = lst[c[i]];
            lst[c[i]] = i;
        }
        int res = dfs(1, n, 0);
        cout << "Case " << ti << ": " << res << '\n';
    }
}
