#include <bits/stdc++.h>
using namespace std;
const int N=20005;
//#define debug
int main(){
    int n,x,y,z,h,mn[N],mx[N],ans=0;
    fill(mn,mn+N,200000);
    fill(mx,mx+N,0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>h;
        z=x+y;
        mn[z]=min(mn[z],h);
        mx[z]=max(mx[z],h);
        #ifdef debug
            printf("%d:%d/%d\n",z,mn[z],mx[z]);
        #endif // debug
    }
    for(int i=1;i<=20000;i++){
        ans=max(ans,mx[i-1]-mn[i]);
        mx[i]=max(mx[i],mx[i-1]);
        #ifdef debug
            printf("%d:%d/%d\n",i,mn[i],mx[i]);
        #endif // debug
    }
    cout<<ans<<'\n';
}
