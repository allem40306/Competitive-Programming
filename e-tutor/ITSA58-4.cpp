#include <iostream>
#include <cmath>
using namespace std;
const int N=1005;
int n,m,adj[N][N],dp[N][N],x,y;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            dp[i][j]=100000;
        }
   }
   for(int k=0;k<m;k++){
       for(int i=0;i<m;i++){
           for(int j=0;j<m;j++){
               dp[i][j]=min(dp[i][j],adj[i][k]+adj[k][j]);
           	}
      	}
   }
   for(int i=0;i<n;i++){
           cin>>x>>y;
           cout<<dp[x][y]<<'\n';
    }       
}        
