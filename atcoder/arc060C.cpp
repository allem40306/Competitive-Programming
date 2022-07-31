#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 1e5;
const int LOG = 20;
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
    int n, L, q;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(LOG));
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> L >> q;
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = lower_bound(a.begin(), a.end(), a[i] + L) - a.begin();
        if (dp[i][0] == n || a[i] + L < a[dp[i][0]])
        {
            dp[i][0] -= 1;
        }
    }
    for (int i = 1; i < LOG; ++i)
        for (int j = 0; j < n; ++j)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a > b)
            swap(a, b);
        int ans = 0;
        for (int i = LOG - 1; i >= 0; --i)
        {
            if (dp[a][i] < b)
            {
                ans += (1 << i);
                a = dp[a][i];
            }
        }
        cout << ans + 1 << '\n';
    }
}
