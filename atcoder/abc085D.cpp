#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int main(){
    int n,h,a[N],b[N],ma=0,ans=0;
    cin>>n>>h;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        ma=max(a[i],ma);
    }
    sort(b,b+n,greater<int>());
    for(int i=0;i<n;i++){
        if(h>0&&b[i]>ma){
            h-=b[i];
            ans++;
        }else{
            break;
        }
    }
    if(h>0){
        cout<<ans+h/ma+(h%ma>0)<<'\n';
    }else{
        cout<<ans<<'\n';
    }
}
