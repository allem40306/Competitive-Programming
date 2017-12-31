#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    while(n){
        ans+=n%10;
        n/=10;
    }
    cout<<ans<<'\n';
}
