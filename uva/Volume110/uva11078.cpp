#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,a[100005],ans,mn,mx;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        mn=a[1]; mx=a[0]; ans=mx-mn;
        for(int i=1;i<n;i++){
            if(a[i]>mx){
                mx=a[i];
                if(i+1==n)continue;
                mn=a[i+1];
            }else if(a[i]<mn){
                mn=a[i];
            }
            ans=max(ans,mx-mn);
        }
        cout<<ans<<'\n';
    }
}
