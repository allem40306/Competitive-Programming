#include <iostream>
using namespace std;
const int N=1005;
const int M=3000;
int dp[N][M];

int main(){
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
    while(cin>>n){
        cout<<n<<"!\n";
        for(ai=M-1;!dp[n][ai];ai--);
        for(;ai>=0;cout<<dp[n][ai--]);
        cout<<'\n';
    }
}
