#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
const int N=20+1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dp[N][N],t,n,x,y,ti=1;
    while(cin>>t){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j]=100;
            }
        }
        for(int i=1;i<N-1;i++){
            if(i>1)cin>>t;
            while(t--){
                cin>>x;
                dp[i][x]=dp[x][i]=1;
            }
        }
        for(int k=1;k<N;k++){
            for(int i=1;i<N;i++){
                for(int j=1;j<N;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        cout<<"Test Set #"<<ti++<<'\n';
        cin>>n;
        while(n--){
            cin>>x>>y;
            cout<<setw(2)<<x<<" to "<<setw(2)<<y<<':'<<setw(2)<<dp[x][y]<<'\n';
        }
        cout<<'\n';
    }
}
