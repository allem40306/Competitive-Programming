#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    long long ans,x;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>x;
            ans+=x;
        }
        cout<<ans<<'\n';
    }
}