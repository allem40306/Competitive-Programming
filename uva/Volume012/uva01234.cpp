#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int p[N],Rank[N];
struct Edge{
    int f,t,w;
    bool operator<(const Edge&rhs)const{
        return w<rhs.w;
    }
};
void init(){
    for(int i=0;i<N;i++){
        p[i]=i;
        Rank[i]=1;
    }
}

int F(int x){return (x==p[x]?(x):(p[x]=F(p[x])));}

bool Union(int a,int b){
    a=F(a),b=F(b);
    if(a==b)return false;
    if(Rank[a]>Rank[b])p[b]=a;
    else if(Rank[a]<Rank[b])p[a]=b;
    else{p[a]=b; Rank[b]++;}
    return true;
}

int main(){
    int t;
    while(cin>>t,t){
        int n,m;
        while(t--){
            cin>>n>>m;
            priority_queue<Edge>pq;
            init();
            for(int i=0,f,t,w;i<m;i++){
                cin>>f>>t>>w;
                pq.push(Edge{f,t,w});
            }
            int ans=0;
            while(!pq.empty()){
                Edge k=pq.top(); pq.pop();
                if(!Union(k.f,k.t)){
                    ans+=k.w;
                }
            }
            cout<<ans<<'\n';
        }
    }
}