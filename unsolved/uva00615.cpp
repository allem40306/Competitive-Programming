#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>v[N];
bool ok,vis[N];
int n,nn;
map<int,int>tb;

void dfs(int x,int tx){
//    cout<<x<<' '<<tx<<'\n';
    nn++;
    vis[tx]=1;
    for(int i=0;i<v[tx].size();i++){
//        cout<<tb[v[tx][i]]<<'+'<<v[tx][i]<<'\n';
        if(vis[tb[v[tx][i]]]||v[tx][i]==x){
            ok=0;
            continue;
        }
        dfs(v[tx][i],tb[v[tx][i]]);
    }
}

int main(){
    int x,y,ti=1,p,h;
    while(cin>>x>>y){
        if(x<0)break;
        h=0;
        for(int i=0;i<N;i++){
            v[i].clear();
        }
        tb.clear();
        n=nn=0;
        while(x||y){
            if(tb.find(x)==tb.end()){
                tb[x]=n;
//                cout<<x<<'*'<<n<<'\n';
                n++;
            }
            if(tb.find(y)==tb.end()){
                tb[y]=n;
//                cout<<y<<'*'<<n<<'\n';
                n++;
            }
            v[tb[x]].push_back(y);
            if(!h||h==y)h=x;
            cin>>x>>y;
        }
        ok=1;
        memset(vis,0,sizeof(vis));
        if(n)dfs(h,tb[h]);
        if(ok&&n==nn){
            cout<<"Case "<<ti++<<" is a tree.\n";
        }else{
            cout<<"Case "<<ti++<<" is not a tree.\n";
        }
    }
}
