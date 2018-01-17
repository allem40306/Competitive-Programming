#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    double ans,pos;
    while(cin>>n>>m){
        ans=0.0;
        for(int i=1;i<n;i++){
            pos=(double)i/n*(n+m);
            ans+=abs(pos-floor(pos+0.5));
        }
        cout<<fixed<<setprecision(4)<<ans*10000/(n+m)<<'\n';
    }
}
