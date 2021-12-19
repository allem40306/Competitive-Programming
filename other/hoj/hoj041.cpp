#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int m, n, ans = 0;
    vector<int>dp;
    cin >> m >> n;
    dp.resize(m + 5);
    for (int i = 1, v, w; i <= n; i++) {
        cin >> v >> w;
        for (int j = 0; (1 << j) <= m; j++) {
            for (int k = m; k - (1 << j)*w >= 0; k--) {
                dp[k] = max(dp[k], dp[k - (1 << j) * w] + (1 << j) * v);
                ans = max(ans, dp[k]);
            }
        }
    }
    cout << ans << '\n';
}