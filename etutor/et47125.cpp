#include <bits/stdc++.h>
using namespace std;

int main(){
    int dp[25]={1};
    for(int i = 1; i <= 20; ++i){
        for(int j = i; j <= 20; ++j){
            dp[j] += dp[j - i];
        }
    }
    int n;
    while(cin >> n){
        cout << dp[n] << '\n';
    }
}