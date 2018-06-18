#include <bits/stdc++.h>
using namespace std;

int main(){
//    freopen("zjc296.txt","r",stdin);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    while(k--){
        ans=(ans+m-1)%v.size();
        v.erase(v.begin()+ans);
    }
    cout<<v[ans%v.size()]<<'\n';
}
