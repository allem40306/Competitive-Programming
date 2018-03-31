#include <bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>v[N];
bool ok,vis[N],used[N];
int n,nn;

void dfs(int x){
    nn++;
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i]]||v[x][i]==x){
            ok=0;
            continue;
        }
        dfs(v[x][i]);
    }
}

int main(){
    int x,y,ti=1,p,h;
    while(cin>>x>>y){
        if(x==-1)break;
        memset(used,0,sizeof(used));
        h=p=0;
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        n=nn=0;
        while(x||y){
            v[x].push_back(y);
            if(!h||h==y)h=x;
            p++;
            if(!used[x]){
                used[x]=1;
                n++;
            }
            if(!used[y]){
                used[y]=1;
                n++;
            }
            cin>>x>>y;
        }
        ok=1;
        memset(vis,0,sizeof(vis));
        if(n)dfs(h);
        if(ok&&n==nn){
            cout<<"Case "<<ti++<<" is a tree.\n";
        }else{
            cout<<"Case "<<ti++<<" is not a tree.\n";
        }
    }
}
