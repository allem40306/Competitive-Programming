#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,ans=100000,t;
    cin>>n;
    while(n--){
        t=0;
        cin>>x;
        while(x%2==0){
            t++;
            x/=2;
        }
        ans=min(ans,t);
    }
    cout<<ans<<'\n';
}
