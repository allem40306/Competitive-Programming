#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,a,x,m,ans;
    vector<long long >v;
    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        for(long long i=0;i<n;i++){
            cin>>a>>x;
            for(long long j=0;j<a;j++){
                v.push_back(x/a);
            }
        }
        sort(v.begin(),v.end());
        m=v[v.size()/2];
        ans=0;
        for(int i=0;i<v.size();i++){
            ans+=abs(v[i]-m);
        }
        cout<<ans<<'\n';
    }
}
