#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int main(){
    int n,ans,x;
    vector<int>v;
    while(cin>>n){
            v.clear();
        while(cin>>x,x!=-1){
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        ans=0;
        for(int i=0;i<min(int(v.size()),n);i++){
            ans+=v[i];
        }
        cout<<ans<<'\n';
    }
}
