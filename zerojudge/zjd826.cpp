#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int main(){
    int n,m,x,a[N],ans,c;
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        ans=c=0;
        for(int i=0;i<m;i++){
            cin>>x;
            a[x]++;
        }
        for(int i=1;i<=n;i++){
            c+=m/n-a[i];
            ans+=abs(c);
        }
        cout<<ans<<'\n';
    }
}
