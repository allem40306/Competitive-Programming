#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    int a[N]={},n,d,x,ans=0;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<N;i++){
        a[i]+=a[i-1];
    }
    for(int i=d;i<N;i++){
        ans=max(ans,a[i]-a[i-d-1]);
    }
    cout<<n-ans<<'\n';
}
