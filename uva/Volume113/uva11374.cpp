#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define MP make_pair
const int N=505;
struct Edge{
    int from,to,w;
};
vector<Edge>E;
vector<int>v[N];

void init(){
    E.clear();
    for(int i=0;i<N;i++){
        v[i].clear();
    }
}

void addEdge(int from,int to,int w){
    v[from].push_back(E.size());
    E.push_back(Edge{from,to,w});
}

void dijkstra(int s,int d[],int p[]){
    d[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>>pq;
    pq.push(MP(d[s],s));
    while(!pq.empty()){
        PII k=pq.top(); pq.pop();
        for(auto it:v[k.second]){
            Edge e=E[it];
            if(d[e.to]>d[e.from]+e.w){
                d[e.to]=d[e.from]+e.w;
                p[e.to]=e.from;
                pq.push(MP(d[e.to],e.to));
            }
        }
    }
}

int main(){
    int n,s,e;
    int ds[N],de[N];
    int ps[N],pe[N];
    vector<int>path;
    bool o=false;
    while(cin>>n>>s>>e){
        if(o)cout<<'\n'; o=true;
        int m;
        cin>>m;
        init();
        for(int i=0,f,t,w;i<m;i++){
            cin>>f>>t>>w;
            addEdge(f,t,w);
            addEdge(t,f,w);
        }
        memset(ds,0x3f,sizeof(ds));
        memset(de,0x3f,sizeof(de));
        memset(ps,-1,sizeof(ps));
        memset(pe,-1,sizeof(pe));
        dijkstra(s,ds,ps);
        dijkstra(e,de,pe);
        int k,ss,ee,ans=ds[e];
        cin>>k;
        for(int i=0,f,t,w;i<k;i++){
            cin>>f>>t>>w;
            if(ds[f]+de[t]+w<ans){
                ans=ds[f]+de[t]+w;
                ss=f; ee=t;
            }
            if(ds[t]+de[f]+w<ans){
                ans=ds[t]+de[f]+w;
                ss=t; ee=f;
            }
        }
        path.clear();
        if(ans==ds[e]){
            int tmp=e;
            while(tmp!=-1){
                path.push_back(tmp);
                tmp=ps[tmp];
            }
            for(int i=path.size()-1;i>=0;i--){
                cout<<path[i];
                if(i)cout<<' ';
            }
            cout<<'\n';
            cout<<"Ticket Not Used\n";
        }else{
            int tmp=ss;
            while(tmp!=-1){
                // cout<<tmp<<' ';
                path.push_back(tmp);
                tmp=ps[tmp];
            }
            for(int i=path.size()-1;i>=0;i--){
                cout<<path[i]<<' ';
            }
            tmp=ee;
            while(tmp!=-1){
                cout<<tmp;
                if(tmp!=e)cout<<' ';
                tmp=pe[tmp];
            }
            cout<<'\n'<<ss<<'\n';
        }
        cout<<ans<<'\n';
    }
}