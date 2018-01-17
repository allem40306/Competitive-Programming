#include <bits/stdc++.h>
using namespace std;
const int N=105;
int djs[N];
int f(int x){return x==djs[x]?x:x=f(djs[x]);}
void init(){
    for(int i=0;i<N;i++){
        djs[i]=i;
    }
}
struct edge{
    int s,t;
    double d;
    edge(){};
    edge(int s,int t,double d):s(s),t(t),d(d){}
    bool operator <(const edge&b)const{
        return d>b.d;
    }
};
int main(){
    int n,t,a,b;
    double x[N],y[N],ans;
    cin>>t;
    edge k;
    priority_queue<edge>q;
    for(int ti=0;ti<t;ti++){
        while(!q.empty()){
            q.pop();
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            for(int j=0;j<i;j++){
                q.push(edge(i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))));
//                cout<<i<<' '<<j<<' '<<sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<<'\n';
            }
        }
        init();
        ans=0;
        while(!q.empty()){
            k=q.top(); q.pop();
            a=f(k.s); b=f(k.t);
            if(a==b)continue;
            djs[a]=djs[b];
//            cout<<k.d<<'\n';
            ans+=k.d;
        }
        if(ti)cout<<'\n';
        cout<<fixed<<setprecision(2)<<ans<<'\n';
    }
}
