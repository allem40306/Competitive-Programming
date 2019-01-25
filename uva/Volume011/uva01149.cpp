#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    bool o=false;
    vector<int>v;
    cin>>t;
    while(t--){
        int n,L,ans=0;
        cin>>n>>L;
        v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        for(;i<j;){
            ans++;
            if(v[i]+v[j]<=L){
                i++; j--;
            }else{
                j--;
            }
        }
        if(i==j)ans++;
        if(o)cout<<'\n'; o=true;
        cout<<ans<<'\n';
    }
}