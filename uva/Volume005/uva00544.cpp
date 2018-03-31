#include <bits/stdc++.h>
using namespace std;
const int N=505;
struct DJS{
    int p[N];
    void init(){
        for(int i=0;i<N;i++){
            p[i]=i;
        }
    }
    int f(int x){return x==p[x]?x:x=f(p[x]);}
}djs;
struct edge{
    int s,t,w;
    edge(){};
    edge(int s,int t,int w):s(s),t(t),w(w){}
    bool operator <(const edge&b)const{
        return w<b.w;
    }
};
vector<edge> v[N];
int ans,e;
void dfs(int f,int p,int w){
    if(p==e){
        ans=w;
        return;
    }
    for(int i=0;i<v[p].size();i++){
        if(v[p][i].t==f)continue;
        dfs(p,v[p][i].t,min(w,v[p][i].w));
    }
}
int main(){
    int n,r,w,ss,tt,p,ti=0;
    string s,t;
    priority_queue<edge>pq;
    edge k;
    while(cin>>n>>r,n||r){
        map<string,int>tb;
        p=0;
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        while(!pq.empty())pq.pop();
        for(int i=0;i<r;i++){
            cin>>s>>t>>w;
            if(tb.find(s)==tb.end()){
                tb[s]=p++;
            }
            if(tb.find(t)==tb.end()){
                tb[t]=p++;
            }
//            cout<<s<<' '<<t<<'\n';
//            cout<<tb[s]<<'-'<<tb[t]<<'-'<<w<<'\n';
            pq.push(edge(tb[s],tb[t],w));
        }
        djs.init();
        while(!pq.empty()){
            k=pq.top(); pq.pop();
            ss=djs.f(k.s); tt=djs.f(k.t);
            if(ss==tt)continue;
            djs.p[ss]=djs.p[tt];
//            cout<<ss<<' '<<tt<<' '<<k.w<<'\n';
            v[k.s].push_back(edge(k.s,k.t,k.w));
            v[k.t].push_back(edge(k.t,k.s,k.w));
        }
        cin>>s>>t;
//        cout<<tb[s]<<' '<<tb[t]<<'\n';
        e=tb[t];
        ans=0;
//        cout<<tb[s]<<' '<<tb[t]<<'\n';
        dfs(tb[s],tb[s],10000);
        cout<<"Scenario #"<<++ti<<"\n";
        cout<<ans<<" tons\n\n";
    }
}
