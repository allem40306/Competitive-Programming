#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,ans,add,last;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=0){
            cout<<"0\n";
            continue;
        }
        ans=0;
        for(long long int i=1;i<=n;i++){
            add=n/i;
            last=n/add;
            ans+=(last-i+1)*add;
            i=last;
        }
        cout<<ans<<'\n';
    }
}
