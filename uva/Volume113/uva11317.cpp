#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int phi[N];
double dp[N], sum[N];
void phi_table(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(phi[i])continue;
        for(int j = i; j < n; j += i){
            if(!phi[j])phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void cal(int n){
    for(int i = 1; i < n; i++){
        for(int j = i + i; j < n; j += i){
            dp[j] += log10(i) * phi[j / i];
        }
    }
    for(int i = 1; i < n; i++){
        dp[i] += dp[i-1];
        sum[i] = sum[i-1] + log10(i);
    }
}

int main(){
    phi_table(N);
    cal(N);
    int ti = 1, n;
    while(cin >> n, n){
        double f = sum[n] * (n - 1) - dp[n];
        cout << fixed << setprecision(0) << "Case " << ti++ << ": " << floor(dp[n] / 100.0) + 1 << " " << floor(f / 100.0) + 1 << "\n";
    }
}