#include <bits/stdc++.h>
using namespace std;
const int N=6;
bool u[N][N];

void dfs(int p,string s){
//    cout<<p<<' '<<s<<'\n';
    if(s.size()==9){
        cout<<s<<'\n';
    }
    for(int i=1;i<=5;i++){
        if(i==p||u[i][p])continue;
        u[i][p]=u[p][i]=1;
        dfs(i,s+char('0'+i));
        u[i][p]=u[p][i]=0;
    }
}

int main(){
    memset(u,0,sizeof(u));
    u[1][4]=u[4][1]=u[2][4]=u[4][2]=1;
    dfs(1,"1");
}
