#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int a[N], dp[N][N];

void init(int n){
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i][i - 1] = 0;
        dp[i][i] = 0;
        a[i] += a[i - 1];
    }
}

void sol(int n){
    for(int d = 1; d < n; ++d){
        for(int L = 1; L + d <= n; ++L){
            int R = L + d;
            int tmp = (a[R] - a[L - 1]);
            dp[L][R] = 100000000;
            for(int k = L; k <= R; ++k){
                dp[L][R] = min(dp[L][R], dp[L][k - 1] + dp[k + 1][R] + tmp - (a[k] - a[k - 1]));
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int main(){
    int n;
    while(cin >>n){
        init(n);
        sol(n);
    }
}