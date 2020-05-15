#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int M=15;
long long int n,f[N][M],p[N][M],x,ans=-10000000000,c[N];

int main(){
    bool b=0;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cin>>f[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            cin>>p[i][j];
        }
    }
    for(int i=1;i<(1<<10);i++){
        for(int j=0;j<n;j++)c[j]=0;
        for(int j=0;j<=9;j++){
            if((i>>j)&1){
                for(int k=0;k<n;k++){
                    if(f[k][j]==1)c[k]++;
                }
            }
        }
        x=0;
        for(int j=0;j<n;j++){
            x+=p[j][c[j]];
        }
        ans=max(ans,x);
    }
    cout<<ans<<'\n';
}
