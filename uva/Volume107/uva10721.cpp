#include <bits/stdc++.h>
using namespace std;
const int N=55;

int main(){
    long long int n,k,m,dp[N][N],dps[N][N];
    while(cin>>n>>k>>m){
        dp[0][0]=dps[0][0]=1;
        for(int i=1;i<=n;i++){
            dps[0][i]=1;
        }
        for(int i=1;i<=k;i++){
            dps[i][0]=0;
            for(int j=1;j<=n;j++){
                if(j-m>0)dp[i][j]=dps[i-1][j-1]-dps[i-1][j-m-1];
                else dp[i][j]=dps[i-1][j-1];
                dps[i][j]=dps[i][j-1]+dp[i][j];
            }
        }
        cout<<dp[k][n]<<'\n';
    }
}
