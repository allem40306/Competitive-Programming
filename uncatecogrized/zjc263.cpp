#include <bits/stdc++.h>
using namespace std;
const int N=50;
typedef long long LL;
int main(){
    static LL arr[N][N]={},dp[N][N][N][N];
    int n,m;
    cin>>n>>m;
    memset(dp,1,sizeof(dp));
    cout<<dp[0][0][0][0];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][i][j]=arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1];
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            for(int x=i;x>=0;x--){
//                for(int y=j;y>=0;y--){
//                    for(int a=0;a<x;a++){
//                        for(int b=0;)
//                    }
//                }
//            }
//        }
//    }
}
