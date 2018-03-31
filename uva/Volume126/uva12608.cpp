#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int main(){
    long long t,w,n,ans,x[N]={0},y[N],tw;
    cin>>t;
    while(t--){
        cin>>w>>n;
        ans=tw=0;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
            ans+=x[i]-x[i-1];
            if(y[i]+tw>w){
                ans+=2*x[i];
                tw=y[i];
            }else if(y[i]+tw==w){
                if(i==n)continue;
                ans+=2*x[i];
                tw=0;
            }else{
                tw+=y[i];
            }
        }
        cout<<ans+x[n]<<'\n';
    }
}
