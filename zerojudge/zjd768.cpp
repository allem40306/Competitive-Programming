#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,l,c[N];
bool vis[N];
vector<int>v[N];

bool dfs(int p,int x){
    c[p]=x;
    vis[p]=1;
    for(auto i:v[p]){
        if(c[i]==c[p]){
//            cout<<i<<' '<<p<<'\n';
//            cout<<c[i]<<' '<<c[p]<<'\n';
            return false;
        }
        if(!vis[i]){
            if(!dfs(i,1-x))
                return false;
        }
    }
    return true;
}

int main(){
    int a,b;
    while(cin>>n,n){
        cin>>l;
        memset(vis,0,sizeof(vis));
        memset(c,-1,sizeof(c));
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        for(int i=0;i<l;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(dfs(0,0)){
            cout<<"BICOLORABLE.\n";
        }else{
            cout<<"NOT BICOLORABLE.\n";
        }
    }
}
