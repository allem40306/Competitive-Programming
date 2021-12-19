#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long LL;
 
int main(){
    static LL t,n,r[N],c[N],dp[N][N],sum=0;
    cin>>t;
    for(int ti=0;ti<t;ti++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>r[i]>>c[i];
        }
        memset(dp,0x7f,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=k-1;i>=0;i--){
                for(int j =k-1;j>=i;j--){
                    dp[i][k]=min(dp[i][k],dp[i][j]+dp[j+1][k]+r[i]*c[j]*c[k]);
                }
            }
        }
        cout<<(dp[0][n-1]+999)/1000<<'\n';
        sum+=dp[0][n-1];
    }
    cout<<(sum+999)/1000<<'\n';
}


