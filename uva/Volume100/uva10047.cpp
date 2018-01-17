#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y,c,d,s;
    node(){};
    node(int x,int y,int c,int d,int s):
        x(x),y(y),c(c),d(d),s(s){}
};
const int N=30;
int n,m,ti=1,sx,sy,tx,ty,ans;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},step[N][N][10][5];
string s[N];
queue<node>q;
bool sol(){
    int nx,ny,nc,nd,ns;
    node k;
    while(!q.empty())q.pop();
    q.push(node(sx,sy,0,0,0));
    memset(step,-1,sizeof(step));
    step[sx][sy][0][0]=0;
    while(!q.empty()){
        k=q.front(); q.pop();
        //left
        nx=k.x; ny=k.y; nc=k.c; nd=(k.d+3)%4; ns=k.s+1;
        if(s[nx][ny]=='.'&&step[nx][ny][nc][nd]==-1){
//            cout<<'('<<nx<<','<<ny<<")->"<<nd<<' '<<ns<<'\n';
            step[nx][ny][nc][nd]=ns;
            q.push(node(nx,ny,nc,nd,ns));
        }
        //right
        nx=k.x; ny=k.y; nc=k.c; nd=(k.d+1)%4; ns=k.s+1;
        if(s[nx][ny]=='.'&&step[nx][ny][nc][nd]==-1){
//            cout<<'('<<nx<<','<<ny<<")->"<<nd<<' '<<ns<<'\n';
            step[nx][ny][nc][nd]=ns;
            q.push(node(nx,ny,nc,nd,ns));
        }
        //stright
        nx=k.x+dx[k.d]; ny=k.y+dy[k.d]; nc=(k.c+1)%5; nd=k.d; ns=k.s+1;
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&step[nx][ny][nc][nd]==-1&&s[nx][ny]=='.'){
//            cout<<'('<<nx<<','<<ny<<")->"<<nd<<' '<<ns<<'\n';
            step[nx][ny][nc][nd]=ns;
            if(nx==tx&&ny==ty&&nc==0){
                ans=step[nx][ny][nc][nd];
                return 1;
            }
            q.push(node(nx,ny,nc,nd,ns));
        }
    }
    return 0;
}
int main(){
//    freopen("10047.txt","w",stdout);
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='S'){
                    sx=i;
                    sy=j;
                    s[i][j]='.';
                }else if(s[i][j]=='T'){
                    tx=i;
                    ty=j;
                    s[i][j]='.';
                }
            }
        }
        if(ti>1)cout<<'\n';
        cout<<"Case #"<<ti++<<"\n";
        if(sol()){
            cout<<"minimum time = "<<ans<<" sec\n";
        }else{
            cout<<"destination not reachable\n";
        }
    }
}
