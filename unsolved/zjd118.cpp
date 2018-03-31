#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,r,ans;
    int n;
    while(cin>>s>>n){
        ans=s.substr(0,n);
        for(int i=1;i+n<=s.size();i++){
            r=s.substr(i,n);
            ans=max(ans,r);
        }
        cout<<ans<<'\n';
    }
}
