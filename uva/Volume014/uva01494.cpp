#include <bits/stdc++.h>
using namespace std;
const int N=1005;
struct Edge{
    int x,y,w;
    Edge(int x,int y,int w):x(x),y(y),w(w){}
    bool operator<(const Edge&b)const{
        return w<b.w;
    }
};
struct DJS{
    int p[N];
    void init(){for(int i=0;i<N;i++)p[i]=i;}
    int f(int x){return (x==p[x]?x:p[x]=f(p[x]));}
}d;
vector<Edge>v,mst[N];
bitset<N>vis;
double maxEdge[N][N];
double krusal(){
    double sum=0;
    d.init();
    for(int i=0;i<N;i++)mst[i].clear();
    for(int i=0;i<v.size();i++){
        int fx=d.f(v[i].x),fy=d.f(v[i].y);
        if(fx==fy)continue;
        d.p[fx]=d.p[fy];
        sum+=sqrt(v[i].w);
        mst[v[i].x].push_back(Edge(v[i].x,v[i].y,v[i].w));
        mst[v[i].y].push_back(Edge(v[i].y,v[i].x,v[i].w));
    }
    return sum;
}
void dfs(int s,int n){
    vis[s]=1;
    for(int i=0;i<mst[s].size();i++){
        int t=mst[s][i].y;
        if(vis[t])continue;
        double cost=sqrt(mst[s][i].w);
        for(int j=0;j<n;j++){
            if(vis[j]){
                maxEdge[j][t]=maxEdge[t][j]=max(maxEdge[j][s],cost);
            }
        }
        dfs(t,n);
    }
}
int main(){
    int t,n,x[N],y[N],p[N];
    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>p[i];
            for(int j=0;j<i;j++){
                v.push_back(Edge(i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
            }
        }
        sort(v.begin(),v.end());
        double mincost=krusal(),ans=0;
        vis.reset();
        dfs(0,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ans=max(ans,((p[i]+p[j])/(mincost-maxEdge[i][j])));
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
}
