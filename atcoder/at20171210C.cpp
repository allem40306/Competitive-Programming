#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,x;
    map<int,int>ma;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        if(ma.find(x)!=ma.end()){
            ma[x]+=1;
        }else{
            ma[x]=1;
        }
    }
    vector<int>v;
    for(auto it:ma){
        v.push_back(it.second);
    }
    sort(v.begin(),v.end());
    int ans=0;
    if(v.size()<=k){
        cout<<"0\n";
        return 0;
    }
    for(int i=0;i<v.size()-k;i++){
        ans+=v[i];
    }
    cout<<ans<<'\n';
}
