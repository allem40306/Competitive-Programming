#include <bits/stdc++.h>
using namespace std;

int sod(int x){
    int v=0;
    while(x){
        v+=x%10;
        x/=10;
    }
    return v;
}

int main(){
    int n,a,b,ans=0,v;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        v=sod(i);
        if(v>=a&&v<=b)ans+=i;
    }
    cout<<ans<<'\n';
}
