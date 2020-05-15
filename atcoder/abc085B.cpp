#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,ans=0,a[105]={};
    cin>>n;
    while(n--){
        cin>>x;
        if(!a[x]){
            ans++;
            a[x]=1;
        }
    }
    cout<<ans<<'\n';
}
