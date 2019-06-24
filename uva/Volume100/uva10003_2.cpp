#include <bits/stdc++.h>
using namespace std;
const int MXN = 55;

int main(){
    int L, n;
    int a[MXN];
    int dp[MXN][MXN];
    while(cin >> L, L){
        cin >> n;
        a[0] = 0;
        a[n + 1] = L;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int d = 1; d <= n + 1; ++d){
            for(int i = 0; i + d <= n + 1; ++i){
                int j = i + d;
                int mn = 1000000;
                for(int k = i + 1; k < j; ++k){
                    mn = min(mn, dp[i][k] + dp[k][j]);
                }
                if(mn != 1000000)dp[i][j] = mn + (a[j] - a[i]);
            }
        }
        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
}