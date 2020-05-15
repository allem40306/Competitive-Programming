#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans=0,tmp=v[0],c=1;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1])c++;
        else{
            if(c!=tmp){
                ans+=(c>tmp?c-tmp:c);
            }
            tmp=v[i];
            c=1;
        }
    }
    if(c!=tmp){
            ans+=(c>tmp?c-tmp:c);
    }
    cout<<ans<<'\n';
}
