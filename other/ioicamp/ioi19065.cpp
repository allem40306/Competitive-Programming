#include <bits/stdc++.h>
using namespace std;
int n;
bitset<3005000>vis;

void dfs(int x,int d,int i){
    // cout<<"de:"<<x<<'-'<<d<<'-'<<i;
    cout<<x<<'\n';
    if(d>n || vis[x])return; vis[x]=1;
    int v=d*(d+1)/2-1+i;
    // cout<<"de:"<<v;
    int vv=v,uu=v+1;
    if(d%2==0)swap(vv,uu);
    dfs(vv,d+1,vv-v+i);
    dfs(uu,d+1,uu-v+i);
    cout<<x<<'\n';
}

int main(){
    cin>>n;
    vis.reset();
    dfs(0,1,1);
}