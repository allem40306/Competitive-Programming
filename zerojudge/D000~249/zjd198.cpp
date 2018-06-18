#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    int t,w,n,x,y;
    long long dp[N][N];
    bool vis[N][N];
    string s;
    cin>>t;
    for(int ti=0;ti<t;ti++){
        cin>>w>>n>>ws;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<w;i++){
            getline(cin,s);
            stringstream ss(s);
            ss>>x;
            while(ss>>y){
                vis[x][y]=1;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for(int i=1;i<=w;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j])continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
//                cout<<i<<j<<' '<<dp[i][j]<<'\n';
            }
        }
        if(ti)cout<<'\n';
        cout<<dp[w][n]<<'\n';
    }
}
