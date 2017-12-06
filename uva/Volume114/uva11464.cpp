#include <bits/stdc++.h>
using namespace std;
const int N=20;
int t,n,a[N][N],b[N][N];
const int INF=10000;

int sol(int x){
    memset(b,0,sizeof(b));
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(x&(1<<(i-1)))b[1][i]=1;
        else if(a[1][i])return INF;
        cnt+=(b[1][i]!=a[1][i]);
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=(b[i-2][j]+b[i-1][j-1]+b[i-1][j+1])%2;
            if(!b[i][j]&&a[i][j])return INF;
            cnt+=(b[i][j]!=a[i][j]);
        }
    }
    return cnt;
}

int main(){
    int ans;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        ans=INF;
        for(int i=0;i<(1<<n);i++){
            ans=min(ans,sol(i));
        }
        cout<<"Case "<<ti<<": "<<(ans==INF?-1:ans)<<'\n';
    }
}
