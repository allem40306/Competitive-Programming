#include <bits/stdc++.h>
using namespace std;
const int N=105;
bool vis[N];
int n,k;
vector<int>v[N];

void dfs(int p){
    vis[p]=1;
    for(int i=0;i<v[p].size();i++){
        if(vis[v[p][i]])continue;
        dfs(v[p][i]);
    }
}

int main(){
    int x,y;
    while(cin>>n>>k){
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        for(int i=0;i<k;i++){
            cin>>x>>y;
            v[x].push_back(y);
        }
        memset(vis,0,sizeof(vis));
        dfs(0);
        if(vis[n]){
            cout<<"Ok!\n";
        }else{
            cout<<"Impossib1e!\n";
        }
    }
}
