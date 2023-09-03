#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
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

int main()
{
    int n, q, si = 0;
    int a[205];
    int dp[205][2500];
    while (cin >> n >> q, n || q)
    {
        cout << "SET " << ++si << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int qi = 1; qi <= q; ++qi)
        {
            int d, m;
            cin >> d >> m;
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for (int i = 0; i < n; ++i)
            {
                int x = (a[i] % d + d) % d; // must in [0,d)
                for (int j = n; j >= 1; --j)
                    for (int k = 200; k - x >= 0; --k)
                    {
                        dp[j][k] += dp[j - 1][k - x];
                    }
            }
            int ans = 0;
            for (int i = 0; i <= 200; i += d)
                ans += dp[m][i];
            cout << "QUERY " << qi << ": " << ans << '\n';
        }
    }
}
