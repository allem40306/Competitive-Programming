#include <bits/stdc++.h>
using namespace std;
const int N = 67;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long int dp[N][N][2] = {};
    int n, k;
    while (cin >> n >> k, n > 0)
    {
        dp[1][1][1] = dp[1][0][0] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j][0];
                if (j)
                    dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1];
            }
        }
        cout << dp[n][k][0] + dp[n][k][1] << '\n';
    }
}
