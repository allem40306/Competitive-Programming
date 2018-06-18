#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N]={},t;
int main(){
    string m,b;
    cin>>m>>b>>t;
    for(int i=1;i<=m.size();i++){
        for(int j=1;j<=b.size();j++){
            if(m[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[m.size()][b.size()]<=t){
        cout<<"sitini na tisa\n";
    }else{
        cout<<"kwa nini unaendesha\n";
    }
}
