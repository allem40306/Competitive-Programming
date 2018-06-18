#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int mod=1000007;
typedef long long LL;
int n,m,dp[N][N]={},a[N];
//#define debug

LL dfs(int i,int r){
    #ifdef debug
        printf("%d %d\n",i,r);
    #endif // debug
    if(dp[i][r])return dp[i][r];
    if(r==0)return 1;
    if(i==0)return 0;
    for(int k=0;k<=a[i];k++){
        if(k<=r){
            dp[i][r]=(dp[i][r]+dfs(i-1,r-k))%mod;
        }
    }
    return dp[i][r];
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(n,m)<<'\n';
}
