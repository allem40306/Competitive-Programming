#include <bits/stdc++.h>
using namespace std;

bool can(string s){
    for(int i=1;i<s.size();i++){
        if(s[i-1]<s[i])return 1;
    }
    return 0;
}

int main(){
    int n,k;
    bool g=0;
    string s,r,t,ans="";
    cin>>n>>k>>s;
    t=r=s;
    if(can(s)&&n>=k)next_permutation(s.begin(),s.end());
    sort(r.begin(),r.end());
    unique(r.begin(),r.end());
    for(int i=0;i<k;i++){
        if(g||i>=n){
            ans+=r[0];
            continue;
        }
        ans+=s[i];
        if(s[i]==r[r.size()-1])g=1;
    }
    cout<<ans<<'\n';
}
