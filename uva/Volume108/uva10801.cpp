#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int INF=16843009;
int n,adj[N][N],d[N];
bool vis[N];
void update_adj(int a,int b,int t){
    if(adj[a][b]>t){
        adj[a][b]=adj[b][a]=t;
    }
}

void dijkstra(){
    int r=0,p,minlen;
    memset(vis,0,sizeof(vis));
    d[0]=0;
    vis[0]=1;
    for(int i=1;i<=99;i++){
        minlen=INF;
        for(int j=1;j<=99;j++){
            if(vis[j])continue;
            d[j]=min(d[j],d[r]+adj[r][j]+60);
            if(minlen>d[j]){
                minlen=d[j];
                p=j;
            }
        }
        if(minlen==INF){
            return;
        }
        r=p;
        vis[r]=1;
    }
}

int main(){
    int m,sr,x,a[N],t[N];
    string s;
    cin.tie(NULL);
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>t[i];
        }
        memset(adj,1,sizeof(adj));
        memset(d,1,sizeof(d));
        cin>>ws;
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream ss(s);
            sr=0;
            while(ss>>a[sr]){
                for(int j=0;j<sr;j++){
                    update_adj(a[sr],a[j],t[i]*(a[sr]-a[j]));
                }
                sr++;
            }
        }
        if(!m){
            cout<<"0\n";
            continue;
        }
        dijkstra();
        if(d[m]==INF){
            cout<<"IMPOSSIBLE\n";
        }else{
            cout<<d[m]-60<<'\n';
        }
    }
}
