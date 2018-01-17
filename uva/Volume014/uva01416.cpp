#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1005;
const int INF=100000000;
typedef long long LL;
struct edge{
    int s,t;
    LL d;
    edge(){};
    edge(int s,int t,LL d):s(s),t(t),d(d){}
};

struct heap{
    LL d;
    int p; //point
    heap(){};
    heap(LL d,int p):d(d),p(p){}
    bool operator <(const heap& b)const{
        return d>b.d;
    }
};

struct Dijkstra{
    int n,m;
    bool vis[N];
    vector<edge>edges;
    vector<int>g[N];
    LL d[N];
    int f[N];
    void init(int nn){
        n=nn;
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        edges.clear();
    }
    void add_edge(int s,int t,LL d){
        edges.push_back(edge(s,t,d));
        g[s].push_back(edges.size()-1);
    }
    void dijkstra(int ss){
        priority_queue<heap>Q;
        for(int i=0;i<n;i++){
            d[i]=INF;
        }
        d[ss]=0;
        f[ss]=-1;
        memset(vis,0,sizeof(vis));
        Q.push(heap(0,ss));
        heap x;
        while(!Q.empty()){
            x=Q.top(); Q.pop();
            int p=x.p;
            if(vis[p])continue;
            vis[p]=1;
            for(int i=0;i<g[p].size();i++){
                edge& e=edges[g[p][i]];
                if(d[e.t]>d[p]+e.d){
                    d[e.t]=d[p]+e.d;
                    f[e.t]=g[p][i];
                    Q.push(heap(d[e.t],e.t));
                }
            }
        }
    }
}d1,d2;

int n,m;
LL L,c[M],ans1,ans2;
edge e[M];
int main(){
    while(cin>>n>>m>>L){
        memset(c,0,sizeof(c));
        d1.init(n);
        int s,t;
        LL d;
        for(int i=0;i<m;i++){
            cin>>s>>t>>d;
            s--; t--;
            e[i]=edge(s,t,d);
            d1.add_edge(s,t,d);
            d1.add_edge(t,s,d);
        }
        ans1=ans2=0;
        for(int i=0;i<n;i++){
            d1.dijkstra(i);
            for(int j=0;j<n;j++){
                if(d1.d[j]==INF)ans1+=L;
                else ans1+=d1.d[j];
            }
            int ss,tt;
            for(int j=0;j<m;j++){
                ss=e[j].s; tt=e[j].t;
                if((d1.f[ss]!=-1&&d1.edges[d1.f[ss]].s==tt)||(d1.f[tt]!=-1&&d1.edges[d1.f[tt]].s==ss)){
                    d2.init(n);
                    for(int k=0;k<m;k++){
                        if(j==k)continue;
                        d2.add_edge(e[k].s,e[k].t,e[k].d);
                        d2.add_edge(e[k].t,e[k].s,e[k].d);
                    }
                    d2.dijkstra(i);
                    for(int k=0;k<n;k++){
                        if(d2.d[k]==INF)c[j]+=L;
                        else c[j]+=d2.d[k];
                    }
                }else{
                    for(int k=0;k<n;k++){
                        if(d1.d[k]==INF)c[j]+=L;
                        else c[j]+=d1.d[k];
                    }
                }
            }
        }
//    for(int i=0;i<m;i++){
//        cout<<c[i]<<'\n';
//    }
        cout<<ans1<<' '<<*max_element(c,c+m)<<'\n';
    }
}
