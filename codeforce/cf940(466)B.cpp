#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    long long n,k,a,b,ans=0;
    cin>>n>>k>>a>>b;
    if(k==1){
        cout<<(n-1)*a<<'\n';
        return 0;
    }
    while(n>1){
        if(n%k){
            ans+=(n%k)*a;
            n-=n%k;
            continue;
        }
        ans+=min(n/k*(k-1)*a,b);
        n/=k;
    }
    cout<<ans-(n==0)*a<<'\n';
}

