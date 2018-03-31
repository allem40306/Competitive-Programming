#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    int n,t[N]={0},x[N]={0},y[N]={0},d;
    cin>>n;
    bool ok=1;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>x[i]>>y[i];
        d=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
//        cout<<d<<'\n';
        if(t[i]-t[i-1]<d||(t[i]-t[i-1])%2!=d%2){
            ok=0;
        }
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";
}
