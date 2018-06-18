#include <bits/stdc++.h>
using namespace std;
int n,m,r,ans;
int vis[5][30];
int ma[30][30];

void print_map(){
//        cout<<'\n';
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            cout<<ma[i][j];
        }
        cout<<'\n';
    }
//        cout<<'\n';
}

void dfs(int d){
    if(d==r){
        ans++;
//        print_map();
        return;
    }
    for(int i=0;i<r;i++){
        if(n&&vis[0][d]==0&&vis[1][i]==0&&vis[2][d+i]==0&&vis[3][i-d+r]==0){
            vis[1][i]++; vis[2][d+i]++; vis[3][i-d+r]++;
            n--;
            ma[d][i]=1;
            dfs(d+1);
            ma[d][i]=0;
            n++;
            vis[1][i]--;vis[2][d+i]--;vis[3][i-d+r]--;
        }
        if(m&&vis[0][d]==0&&vis[1][i]<=0&&vis[2][d+i]<=0&&vis[3][i-d+r]<=0){
            vis[1][i]++;vis[2][d+i]--;vis[3][i-d+r]--;
            m--;
            ma[d][i]=2;
            dfs(d+1);
            ma[d][i]=0;
            m++;
            vis[1][i]--; vis[2][d+i]++; vis[3][i-d+r]++;
        }
    }
}

int main(){
//    freopen("b510.txt","w",stdout);
    cin>>n>>m;
    r=n+m;
    ans=0;
    memset(vis,0,sizeof(vis));
    memset(ma,0,sizeof(ma));
    dfs(0);
    cout<<ans<<'\n';
}
