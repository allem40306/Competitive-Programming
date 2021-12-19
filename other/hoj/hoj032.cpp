#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    vector<int>v,ran,dp;
    cin>>n;
    v.resize(n);
    ran.resize(100005);
    for(int i=0;i<n;i++){
        cin>>v[i];
        ran[v[i]]=i;
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]=ran[v[i]];
    }
    dp.resize(n);
    fill(dp.begin(),dp.end(),1000000);
    for(int i=0;i<n;i++){
        *lower_bound(dp.begin(),dp.end(),v[i])=v[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]!=1000000)ans++;
    }
    cout<<ans<<'\n';
    int i=0;
}

