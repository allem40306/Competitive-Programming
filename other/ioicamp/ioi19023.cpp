#include <bits/stdc++.h>
using namespace std;
const int N=15;
#define MP make_pair
typedef pair<int,int> PII;
int dx[N]={0,1,0,-1};
int dy[N]={1,0,-1,0};
bool vis[N][N];
int main(){
    int n=10;
    int a[N][N]={};
    int tot=1;
    queue<PII>q;
    q.push(MP(5,5));
    vis[5][5]=1;
    while(!q.empty()){
        PII k=q.front(); q.pop();
        int x=k.first,y=k.second;
        a[x][y]=tot++;
        if(tot>100)break;
        for(int i=0;i<4;i++){
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(xx<0||10<=xx||yy<0||10<=yy)continue;
            if(vis[xx][yy])continue;
            vis[xx][yy]=1;
            q.push(MP(xx,yy));
            // cout<<xx<<' '<<yy<<'\n';
        }
    }

    cout<<n<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j)cout<<' ';
            cout<<setw(2)<<a[i][j];
        }
        cout<<'\n';
    }
}