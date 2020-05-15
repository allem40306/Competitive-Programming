#include <bits/stdc++.h>
using namespace std;
const int N=55;
struct loc{
    int x,y;
    loc(){};
    loc(int x,int y):x(x),y(y){}
};
int main(){
    int h,w,p,ans[N][N];
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},xx,yy;
    string s[N];
    cin>>h>>w;
    p=h*w;
    for(int i=0;i<h;i++){
        cin>>s[i];
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')p--;
        }
    }
    memset(ans,-1,sizeof(ans));
    queue<loc>q;
    loc k;
    ans[0][0]=0;
    q.push(loc(0,0));
    while(!q.empty()){
        k=q.front(); q.pop();
        for(int i=0;i<4;i++){
            xx=dx[i]+k.x; yy=dy[i]+k.y;
            if(xx<0||xx>=h||yy<0||yy>=w||ans[xx][yy]!=-1||s[xx][yy]=='#')continue;
            ans[xx][yy]=ans[k.x][k.y]+1;
//            cout<<xx<<yy<<' '<<ans[xx][yy]<<'\n';
            q.push(loc(xx,yy));
        }
    }
    if(ans[h-1][w-1]==-1){
        cout<<-1<<'\n';
    }else{
        cout<<p-ans[h-1][w-1]-1<<'\n';
    }
}
