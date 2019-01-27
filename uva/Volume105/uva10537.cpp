#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
typedef long long LL;
typedef pair<LL,int> PII;
const int N=150;
vector<int> v[N];
int p[N];
LL d[N];
bitset<N>vis;

void init(){
    for(int i=0;i<N;i++){
        v[i].clear();
    }
}

void addEdge(int f,int t){
    v[f].push_back(t);
}

void dijkstra(int s,LL c){
    priority_queue<PII,vector<PII>,greater<PII>>pq;
    memset(d,0x3f,sizeof(d));
    vis.reset();
    d[s]=c; p[s]=-1;
    pq.push(MP(d[s],s));
    while(!pq.empty()){
        PII k=pq.top(); pq.pop();
        // cout<<k.first<<' '<<char(k.second)<<'\n';
        int u=k.second;
        if(vis[u])continue; vis[u]=1;
        for(auto it:v[u]){
            LL w;
            if(u<'a')w=ceil(d[u]/1.0/19*20);
            else w=d[u]+1;
            if(d[it]>w||(d[it]==w&&u<p[it])){
                d[it]=w;
                p[it]=u;
                pq.push(MP(d[it],it));
            }
        }
    }
}

int main(){
    int n,ti=1;
    while(cin>>n,n!=-1){
        init();
        char ch,ch2;
        for(int i=0,w;i<n;i++){
            cin>>ch>>ch2;
            addEdge((int)ch,(int)ch2);
            addEdge((int)ch2,(int)ch);
        }
        LL c;
        int s,e;
        cin>>c>>ch>>ch2;
        s=(int)ch; e=(int)ch2;
        dijkstra(e,c);
        cout<<"Case "<<ti++<<":\n";
        cout<<d[s]<<'\n';
        cout<<char(s);
        while(p[s]!=-1){
            s=p[s];
            cout<<'-'<<char(s);
        }
        cout<<'\n';
    }
}