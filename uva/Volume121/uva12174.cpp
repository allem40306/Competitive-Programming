#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,a[N],cnt[N];
bitset<N>bw,fw;

void sol(){
    memset(cnt,0,sizeof(cnt));
    bw.reset(); fw.reset();
    int ans=0,diffnum=0;
    for(int i=0;i<n+m;i++){
        if(i-n+1>=0&&diffnum==n){
            bw[i-n]=1;
        }
        if(i-n>=0){
            cnt[a[i-n]]--;
            if(cnt[a[i-n]]==0)diffnum--;
        }
        if(i>=m){
            diffnum++;
        }else{
            if(cnt[a[i]]==0)diffnum++;
            cnt[a[i]]++;
        }
        if(i<n&&diffnum==i+1){
            fw[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(i&&!fw[i-1])continue;
        bool ok=1;
        for(int j=i;j<m&&ok;j+=n)ok&=bw[j];
        ans+=ok;
    }
    cout<<ans<<'\n';
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        sol();
    }
}
