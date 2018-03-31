#include <bits/stdc++.h>
using namespace std;
const int N=500005;
struct node{
    int t,w;
    node(){};
    node(int t,int w):t(t),w(w){}
    bool operator <(const node&b)const{
        return w>b.w;
    }
};
int d[N],n,m,s,t,w;
bool vis[N];
vector<node>v[N];
void dijkstra(int x){
    for(int i=1;i<=n;i++){
        d[i]=100000000;
        vis[i]=false;
    }
    priority_queue<node>pq;
    d[x]=0;
    pq.push(node(x,0));
    node k;
    while(!pq.empty()){
        k=pq.top(); pq.pop();
        if(vis[k.t])continue;
        vis[k.t]=1;
        for(auto it:v[k.t]){
            if(d[it.t]>d[k.t]+it.w){
                d[it.t]=d[k.t]+it.w;
                pq.push(node(it.t,d[it.t]));
            }
        }
    }
}

int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=0;i<m;i++){
            cin>>s>>t>>w;
            v[s].push_back(node(t,w));
        }
        dijkstra(1);
        cout<<d[n]<<'\n';
    }
}
