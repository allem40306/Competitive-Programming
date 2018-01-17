#include <bits/stdc++.h>
using namespace std;
const int N=2005;
const int M=3000;
int dp[N][M];

int main(){
//    freopen("text.txt","w",stdout);
    dp[0][0]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<M;j++){
            dp[i][j]=dp[i-1][j]*i;
        }
        for(int j=0;j<M-1;j++){
            dp[i][j+1]+=dp[i][j]/10;
            dp[i][j]%=10;
        }
    }
    int n,ai;
    for(int n=1;n<=2000;n++){
//        cout<<n<<"! ";
        for(ai=0;!dp[n][ai];ai++);
        cout<<dp[n][ai];
    }
}
