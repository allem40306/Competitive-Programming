#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sol(LL a,LL b,LL mod){
    LL ans=0;
    for(;b;b>>=1,a<<=1,a=a>=mod?a-mod:a){
        if(b&1){
            ans+=a;
            ans=ans>=mod?ans-mod:ans;
        }
    }
    return ans;
}

int main(){
    LL a,b,n;
    while(cin>>a>>b>>n){
        cout<<sol(a%n,b%n,n)<<'\n';
    }
}
