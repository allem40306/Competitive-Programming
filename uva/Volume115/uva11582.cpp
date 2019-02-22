#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=1005;
int p[N]; //preiod
int f[N][N*6];
void build(){
    for(int i=2;i<N;i++){
        f[i][0]=0; f[i][1]=1;
        for(int j=2;;j++){
            f[i][j]=(f[i][j-1]+f[i][j-2])%i;
            // cout<<i<<' '<<j<<'\n';
            if(f[i][j-1]==0&&f[i][j]==1){
                p[i]=j-1;
                break;
            }
        }
    }
}
int Pow(ULL a,ULL b,int n){
    if(!b)return 1;
    int ret=Pow(a,b/2,n);
    ret=ret*ret%n;
    if(b&1)ret=ret*a%n;
    return ret;
}

int sol(ULL a,ULL b,int n){
    if(a==0||n==1)return 0;
    int P=Pow(a%p[n],b,p[n]);
    return f[n][P];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    build();
    ULL a,b;
    int t,n;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        cout<<sol(a,b,n)<<'\n';
    }
}