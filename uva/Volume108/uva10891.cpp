#include <bits/stdc++.h>
using namespace std;
const int MXN = 105;
int a[MXN], s[MXN], dp[MXN][MXN], f[MXN][MXN], g[MXN][MXN];

int main(){
    int n;
    while(cin >> n, n){
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            s[i] = a[i] + s[i - 1];
            dp[i][i] = f[i][i] = g[i][i] = a[i];
        }
        for(int len = 1; len != n; ++len){
            for(int i = 1; i + len <= n; ++i){
                int j = i + len;
                dp[i][j] = s[j] - s[i - 1] - min(0, min(f[i + 1][j], g[i][j - 1]));
                f[i][j] = min(dp[i][j], f[i + 1][j]);
                g[i][j] = min(dp[i][j], g[i][j - 1]);
            }
        }
        cout << 2 * dp[1][n] - s[n] << '\n';
    }
}