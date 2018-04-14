#include <bits/stdc++.h>
using namespace std;
const int N=8;
array<int,10>ans[200],tmp;
bool vis[3][20];
int ansi=0;
//#define debug

void dfs(int d){
    if(d>8){
        ans[ansi]=tmp;
        ansi++;
        return;
    }
    for(int i=1;i<=8;i++){
        if(vis[0][i]||vis[1][i+d]||vis[2][i-d+N])continue;
        vis[0][i]=vis[1][i+d]=vis[2][i-d+N]=1;
        tmp[d]=i;
        dfs(d+1);
        vis[0][i]=vis[1][i+d]=vis[2][i-d+N]=0;
    }
    return;
}

int cmp(int x){
    int v=0;
    for(int i=1;i<=8;i++){
        v+=(tmp[i]!=ans[x][i]);
    }
    return v;
}

int main(){
    int ti=1;
    dfs(1);
    while(cin>>tmp[1]){
        for(int i=2;i<=8;i++){
            cin>>tmp[i];
        }
        int ans=8;
        for(int i=0;i<ansi;i++){
            ans=min(ans,cmp(i));
        }
        cout<<"Case "<<ti++<<": ";
        cout<<ans<<'\n';
    }
}
