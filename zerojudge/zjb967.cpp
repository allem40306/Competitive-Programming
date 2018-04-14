#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>v[N];
int n,a,b,tmp;
bitset<N> h;
//#define debug
int dfs(int i){
    #ifdef debug
        printf("%d~\n",i);
    #endif // debug
    int x=0,y=0,z;
    for(int j=0;j<v[i].size();j++){
        z=dfs(v[i][j]);
        #ifdef debug
            printf("%d=%d\n",v[i][j],z);
        #endif // debug
        if(z>x){y=x; x=z;}
        else if(z>y){y=z;}
    }
    #ifdef debug
        printf("%d(%d) %d %d\n",i,v[i].size(),x,y);
    #endif // debug
    tmp=max(tmp,x+y);
    return x+1;
}

int main(){
    while(cin>>n){
        h=-1; tmp=-1;
        h.set();
        for(int i=0;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            cin>>a>>b;
            h[b]=0;
            v[a].push_back(b);
        }
        for(int i=0;i<n;i++){
            if(!h[i])continue;
            dfs(i);
            cout<<tmp<<'\n';
        }
    }
}
