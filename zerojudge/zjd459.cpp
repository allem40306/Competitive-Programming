#include <bits/stdc++.h>
using namespace std;
const int N=20005;
vector<int>v[N];
bool vis[N]={};
int ans[N];

int dfs(int p){
    vis[p]=1;
    for(int i=0;i<v[p].size();i++){
        if(vis[v[p][i]])continue;
        ans[p]+=dfs(v[p][i]);
    }
    return ans[p];
}

int main(){
    int n,s,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans[i]=1;
    }
    for(int i=0;i<n-1;i++){
        cin>>s>>t;
        v[s].push_back(t);
        v[t].push_back(s);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<setw(5)<<i<<'-'<<setw(5)<<ans[i]<<'\n';
    }
}
