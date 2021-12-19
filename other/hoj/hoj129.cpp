#include <bits/stdc++.h>
using namespace std;
const int N=3005;
bool a[N][N]={};
int main(){
    int n,m,ans=0;
    int sL[N]={},sR[N]={},L[N]={},R[N]={},h[N]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]){
                sL[j]=sL[j-1]+1;
                h[j]++;
            }else{
                sL[j]=h[j]=0;
            }
        }
        for(int j=m;j>0;j--){
           if(a[i][j]){
                sR[j]=sR[j+1]+1;
            }else{
                sR[j]=0;
            } 
        }
        for(int j=1;j<=m;j++){
            L[j]=(L[j]!=0?min(L[j],sL[j]):sL[j]);
            R[j]=(R[j]!=0?min(R[j],sR[j]):sR[j]);
            // cout<<i<<'*'<<j<<'\n';
            // cout<<L[j]<<' '<<R[j]<<' '<<h[j]<<'\n';
            ans=max(ans,(L[j]+R[j]-1)*h[j]);
        }
    }
    cout<<ans<<'\n';
}

