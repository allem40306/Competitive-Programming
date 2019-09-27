#include <bits/stdc++.h>
using namespace std;
const int MXN = 20;
int dp[MXN][MXN];

int main(){
    dp[0][0] = 1;
    for(int i = 1; i <= 13; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
}