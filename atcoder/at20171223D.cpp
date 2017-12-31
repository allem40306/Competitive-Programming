#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=s.size();
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
           ans=min(ans,max(i,int(s.size()-i)));
        }
    }
    cout<<ans<<'\n';
}

