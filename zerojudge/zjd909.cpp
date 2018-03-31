#include <bits/stdc++.h>
using namespace std;

struct edge{
    int s,t,w;
    edge(){};
    edge(int s,int t,int w):
        s(s),t(t),w(w){}
    bool operator <(const edge&b)const{
        return w>b.w;
    }
};

const int N=10005;
struct DJS{
    int p[N];
    void init(){
        for(int i=0;i<N;i++){
            p[i]=i;
        }
    }
    int f(int x){return x==p[x]?x:f(p[x]);}
}djs;

int main(){
    priority_queue<edge>pq;
    int n,m,s,t,w,ans=0;
    cin>>n>>m;
    djs.init();
    for(int i=0;i<m;i++){
        cin>>s>>t>>w;
        pq.push(edge(s,t,w));
    }
    edge k;
    int ss,tt;
    while(!pq.empty()){
        k=pq.top(); pq.pop();
        ss=djs.f(k.s);
        tt=djs.f(k.t);
        if(ss==tt)continue;
        ans+=k.w;
        djs.p[ss]=djs.p[tt];
    }
    cout<<ans<<'\n';
}
