#include <bits/stdc++.h>
using namespace std;
const int N=100001;
int n,c,ss[N],tt[N],cc[N],pre[2*N],a[2*N];
int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>ss[i]>>tt[i]>>cc[i];
    }
    memset(a,0,sizeof(a));
    for(int i=1;i<=c;i++){
        memset(pre,0,sizeof(pre));
        for(int j=0;j<n;j++){
            if(cc[j]!=i)continue;
            pre[ss[j]*2-1]++;
            pre[tt[j]*2]--;
        }
        for(int j=1;j<=2*N-2;j++){
            pre[j]+=pre[j-1];
            if(pre[j]>0)a[j]++;
        }
    }
    int ans=0;
    for(int i=1;i<=2*N-2;i++)ans=max(ans,a[i]);
    cout<<ans<<'\n';
}
