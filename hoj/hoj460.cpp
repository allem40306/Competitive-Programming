#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MXN = 10005;

int main()
{
    int t, n, s;
    LL dp[MXN];
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0, x; i != n; ++i)
        {
            cin >> x;
            for(int j = x; j <= s; ++j)
            {
                dp[j] = dp[j] + dp[j - x];
            }
        }
        cout << dp[s] << '\n';
    }
}