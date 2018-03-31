#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int>ma;
    int t,n,x,ans,L;
    cin>>t;
    while(t--){
        cin>>n;
        ans=n;
        L=1;
        ma.clear();
        for(int i=1;i<=n;i++){
            cin>>x;
            if(ma.find(x)!=ma.end()){
                ans=min(ans,i-L);
                L=ma[x]+1;
            }
            ma[x]=i;
        }
        cout<<ans<<'\n';
    }
}
