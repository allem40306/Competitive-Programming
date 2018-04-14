#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,ax,ay,bx,by,bfs[N][N];
string s[N];

struct node{
    int x,y,s;
    node(){};
    node(int x,int y,int s):x(x),y(y),s(s){}
};
queue<node>q;
node k;

void sol(){
    while(!q.empty()){
        k=q.front(); q.pop();
//        cout<<k.x<<' '<<k.y<<'\n';
        if(k.s){
            if(k.y+1<m&&bfs[k.x][k.y+1]==-1&&s[k.x][k.y+1]!='#'){
                bfs[k.x][k.y+1]=bfs[k.x][k.y]+1;
                q.push(node(k.x,k.y+1,0));
            }
            if(k.y>0&&bfs[k.x][k.y-1]==-1&&s[k.x][k.y-1]!='#'){
                bfs[k.x][k.y-1]=bfs[k.x][k.y]+1;
                q.push(node(k.x,k.y-1,0));
            }
        }else{
            if(k.x+1<n&&bfs[k.x+1][k.y]==-1&&s[k.x+1][k.y]!='#'){
                bfs[k.x+1][k.y]=bfs[k.x][k.y]+1;
                q.push(node(k.x+1,k.y,1));
            }
            if(k.x>0&&bfs[k.x-1][k.y]==-1&&s[k.x-1][k.y]!='#'){
                bfs[k.x-1][k.y]=bfs[k.x][k.y]+1;
                q.push(node(k.x-1,k.y,1));
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cin>>ax>>ay>>bx>>by;
    ax--; ay--; bx--; by--;
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int ans=10000000;
    for(int i=0;i<n;i++){
        memset(bfs,-1,sizeof(bfs));
        bfs[ax][ay]=0;
        if(ax+dx[i]==-1||ax+dx[i]==n||ay+dy[i]==-1||ay+dy[i]==m||s[ax+dx[i]][ay+dy[i]]=='#')continue;
        bfs[ax+dx[i]][ay+dy[i]]=1;
        q.push(node(ax+dx[i],ay+dy[i],i>1));
        sol();
        if(bfs[bx][by]!=-1)ans=min(ans,bfs[bx][by]);
//        cout<<'\n';
    }
    if(ans==10000000)ans=-1;
    cout<<ans<<'\n';
}
