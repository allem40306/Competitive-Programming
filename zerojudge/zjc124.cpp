#include <bits/stdc++.h>
using namespace std;
const int N=35;
struct node{
    int x,y,z;
    node(){};
    node(int x,int y,int z):
        x(x),y(y),z(z){}
};
int dx[6]={0,0,0,0,1,-1},dy[6]={0,0,1,-1,0,0},dz[6]={1,-1,0,0,0,0};
int main(){
    int l,c,r,ans[N][N][N];
    string s[N][N];
    node ss,ee,kk;
    queue<node>q;
    while(cin>>l>>c>>r,l){
        memset(ans,-1,sizeof(ans));
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                cin>>s[i][j];
                for(int k=0;k<r;k++){
                    if(s[i][j][k]=='S'){
                        ss=node(i,j,k);
                    }
                    if(s[i][j][k]=='E'){
                        ee=node(i,j,k);
                        s[i][j][k]='.';
                    }
                }
            }
        }
        q.push(ss);
        ans[ss.x][ss.y][ss.z]=0;
        int xx,yy,zz;
        while(!q.empty()){
            kk=q.front(); q.pop();
            for(int i=0;i<6;i++){
                xx=kk.x+dx[i]; yy=kk.y+dy[i]; zz=kk.z+dz[i];
                if(xx<0||yy<0||zz<0||xx>l||yy>c||zz>r)continue;
                if(s[xx][yy][zz]=='.'&&ans[xx][yy][zz]==-1){
                    ans[xx][yy][zz]=ans[kk.x][kk.y][kk.z]+1;
                    q.push(node(xx,yy,zz));
                }
            }
        }
        if(ans[ee.x][ee.y][ee.z]==-1){
            cout<<"Trapped!\n";
        }else{
            cout<<"Escaped in "<<ans[ee.x][ee.y][ee.z]<<" minute(s).\n";
        }
    }
}
