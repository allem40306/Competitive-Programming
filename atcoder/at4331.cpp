/*
source: ABC 125 D Flipping Signs
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;
using LL = long long;
LL a[MXN], dp[MXN][2];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if(a[2] >= 0)
    {
        dp[2][0] = (a[1] + a[2]);
        dp[2][1] = -(a[1] + a[2]);
    }
    else
    {
        dp[2][0] = -(a[1] + a[2]);
        dp[2][1] = (a[1] + a[2]);
    }
    for(int i = 3; i <= n; ++i)
    {
        if(a[i] >= 0)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            dp[i][1] = max(dp[i - 1][0] - 2 * abs(a[i - 1]), dp[i - 1][1] + 2 * abs(a[i - 1])) - a[i];
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0] - 2 * abs(a[i - 1]), dp[i - 1][1] + 2 * abs(a[i - 1])) - a[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
        }
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}