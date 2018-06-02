#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int m,n,x,y,deg[N],ord[N];
bool adj[N][N];

bool cmp(int a,int b){
    return deg[a]>deg[b];
}

struct Djs{
    int p[N],g[N];
    void init(int n){
        for(int i=0;i<=n;i++){
            p[i]=i;
            g[i]=1;
        }
        return;
    }
    int f(int x){
        return p[x]==x?x:x=f(p[x]);
    }
    int Union(int a,int b){
        int fa=f(a),fb=f(b);
        if(fa!=fb){
            p[fa]=fb;
            g[fb]+=g[fa];
        }
        return g[fb]*min(deg[a],deg[b]);
    }
};

int main(){
    Djs d;
    while(cin>>n>>m){
        memset(deg,0,sizeof(deg));
        memset(adj,0,sizeof(adj));
        for(int i=0;i<n;i++){
            ord[i]=i+1;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            adj[x][y]=adj[y][x]=1;
            deg[x]++; deg[y]++;
        }
        sort(ord,ord+n,cmp);
        d.init(n);
        memset(deg,0,sizeof(deg));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(!adj[ord[i]][ord[j]])continue;
                deg[ord[i]]++; deg[ord[j]]++;
                ans=max(ans,d.Union(ord[i],ord[j]));
            }
        }
        cout<<ans<<'\n';
    }
}
