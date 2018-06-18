#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int main(){
    int n,m,x,a[N],d[N];
    bool stop[N],adj[N][N];
    cin>>n>>m;
    memset(adj,0,sizeof(adj));
    memset(d,0,sizeof(d));
    while(m--){
        cin>>x;
        memset(stop,0,sizeof(stop));
        for(int i=0;i<x;i++){
            cin>>a[i];
            stop[a[i]]=1;
        }
        for(int i=a[0];i<a[x-1];i++){
            if(!stop[i]){
                for(int j=0;j<x;j++){
                    if(adj[a[j]][i])continue;
                    adj[a[j]][i]=1;
                    d[i]++;
                }
            }
        }
    }
    queue<int>q;
    int nn=n,ans=0,k;
    while(nn>0){
        ans++;
        for(int i=1;i<=n;i++){
            if(d[i]==0){
                q.push(i);
                d[i]=-1;
                nn--;
            }
        }
        while(!q.empty()){
            k=q.front(); q.pop();
            for(int i=1;i<=n;i++){
                if(adj[k][i]){
                    d[i]--;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
