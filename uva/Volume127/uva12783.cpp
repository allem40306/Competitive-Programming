#include <bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> g[N];
vector<pair<int,int>>ans;
bitset<N>vis;
int dep[N],low[N];

void dfs(int s,int cur,int p){
    vis[s]=true;
    dep[s]=low[s]=cur;
    for(int i:g[s]){
        if(vis[i]){
            if(i!=p&&low[s]>dep[i]){
                low[s]=dep[i];
            }
        }else{
            dfs(i,cur+1,s);
            if(low[s]>low[i]){
                low[s]=low[i];
            }
            if(dep[s]<low[i]){
                ans.push_back({min(i,s),max(i,s)});
            }
        }
    }
}

int main(){
    int n,m;
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++)g[i].clear();
        ans.clear();
        for(int i=0,x,y;i<m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vis.reset();
        dfs(0,0,-1);
        sort(ans.begin(),ans.end());
        cout<<ans.size();
        for(auto it:ans){
            cout<<' '<<it.first<<' '<<it.second;
        }
        cout<<'\n';
    }
}