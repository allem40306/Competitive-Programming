#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,x,ans=0;
    vector<long long int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i&1){
            ans+=v[i];
        }else{
            ans-=v[i];
        }
    }
    cout<<abs(ans)<<'\n';
}