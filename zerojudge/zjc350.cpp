#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,w,r,ans=0;
    cin>>n>>k>>w;
    while(n/k){
        ans+=(n/k)*k;
        r=(n/k)*w;
        n%=k;
        n+=r;
    }
    cout<<ans+n<<'\n';
}
