#include <bits/stdc++.h>
using namespace std;
const int N=2005;
const int INF=1000000;
struct Edge{
    Edge(){};
    int s,t,w;
};

int main(){
    int t,n,m;
    Edge e[N];
    int d[N];
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>e[i].s>>e[i].t>>e[i].w;
        }
        for(auto it:d)it=INF;
        d[0]=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                d[e[j].s]=min(d[e[j].s],d[e[j].t]+e[j].w);
            }
        }
        bool nr=0;
        for(int i=0;i<m;i++){
            if(d[e[i].s]>d[e[i].t]+e[i].w){
                nr=1;
                break;
            }
        }
        cout<<(nr?"possible\n":"not possible\n");
    }
}
