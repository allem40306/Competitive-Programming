#include<bits/stdc++.h>
using namespace std;
const int N = 12;
long long dp[N + 5];

int main(){
    int m;
    long long n;
    dp[0] = 1;
    for(int i = 1; i <= N; ++i)dp[i] = i * dp[i - 1];
    cin >> m;
    while(m--)
    {
        cin >> n;
        for(int i = 1; i <= N; ++i)
        {
            if(dp[i] % n)continue;
            cout << i << '\n';
            break;
        }
    }
}
