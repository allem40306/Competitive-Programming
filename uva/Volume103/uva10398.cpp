#include <bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int>v[N];
bool vis[N];
int x,y,st,path[N];

void dfs(int p,int d){
    vis[p]=1;
    path[d]=p;
    if(p==y){
        st=d;
        return;
    }
    for(auto i:v[p]){
        if(vis[i])continue;
        dfs(i,d+1);
        if(st!=-1)return;
    }
}

int main(){
//    freopen("test.txt","w",stdout);
    int n,l;
    while(cin>>n,n){
        for(int i=0;i<N;i++)v[i].clear();
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin>>l;
        for(int i=0;i<l;i++){
            cin>>x>>y;
            memset(vis,0,sizeof(vis));
            st=-1;
            dfs(x,0);
            if(st%2){
                cout<<"The fleas jump forever between "<<min(path[st/2],path[st/2+1])<<" and "<<max(path[st/2],path[st/2+1])<<".\n";
            }else{
                cout<<"The fleas meet at "<<path[st/2]<<".\n";
            }
        }
//        cout<<"QQQ\n";
    }
}
