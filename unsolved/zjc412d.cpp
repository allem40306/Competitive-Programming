#include <bits/stdc++.h>
using namespace std;
const long long int mod=1000000007;

long long int calc(int n){
    long long int v=0;
    for(int i=1;i<n;i++){
        v+=i*(n-i);
        v%=mod;
    }
    return v;
}

int main(){
    long long int t,n,ans,st,i,m;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        i=st=0;
        n=ans=m=1;
        for(;i<s.size()&&s[i]!='O';i++);
        i++;
        for(;i<s.size();i++){
            if(s[i]=='O'){
                if(st){
                    ans*=m;
                    ans%=mod;
                    m=1;
                    n++;
                }else{
                    m++;
                }
                st=0;
            }else if(s[i]=='w'){
                if(st){
                   m++;
                }else{
                    ans*=m;
                    ans%=mod;
                    m=1;
                }
                st=1;
            }
        }
        if(!st){
            ans*=m;
            ans%=mod;
        }
        ans*=calc(n);
        ans%=mod;
        cout<<ans<<'\n';
    }
}
