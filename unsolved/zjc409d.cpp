#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,x;
vector<int>arr[N],dp[N];
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        arr[i].resize(m+1);
        dp[i].resize(m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            arr[i][j]=dp[i][j]=x;
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int a=0;a<i;a++){
                for(int b=0;b<j;b++){
                    dp[i][j]=max(dp[i][j],dp[a][b]+arr[i][j]-arr[a+1][b]-arr[a][b+1]+arr[a][b]);
                }
            }
        }
    }
    int ans=dp[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
}
