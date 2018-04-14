#include <bits/stdc++.h>
using namespace std;
const int N=205;
const int M=2005;
struct Node{
    int w,v;
    bool operator <(const Node&b)const{
        return w>b.w;
    }
};
//#define debug
int main(){
    Node a[N];
    int n,t,L;
    cin>>n>>t>>L;
    for(int i=0;i<n;i++){
        cin>>a[i].w>>a[i].v;
    }
    sort(a,a+n);
    int dp[N][M]={};
    for(int i=0;i<n;i++){
        for(int j=L-1,jj=a[i].w*L;j;j--,jj-=a[i].w){
            if(jj>t)continue;
            for(int k=t-jj;k>=0;k--){
                if(dp[j][k]){
                    dp[j+1][k+jj]=max(dp[j+1][k+jj],dp[j][k]+a[i].v);
                }
            }
        }
        dp[1][a[i].w]=max(dp[1][a[i].w],a[i].v);
    }
    int ans=0;
    for(int i=1;i<=L;i++){
        for(int j=0;j<=t;j++){
            #ifdef debug
                if(dp[i][j])printf("%d %d %d\n",i,j,dp[i][j]);
            #endif // debug
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
}
