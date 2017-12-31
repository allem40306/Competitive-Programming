#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long x,y,ans=0;
    cin>>x>>y;
    while(x<=y){
        ans++;
        x*=2;
    }
    cout<<ans<<'\n';
}
