#include <bits/stdc++.h>
using namespace std;
const int N=105;
int m,n,lo,no,tmp;
string s[N];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void bfs(int x,int y){
    tmp=1;
    char ch=s[x][y];
    s[x][y]='0';
    queue<int>qx,qy;
    qx.push(x); qy.push(y);
    while(!qx.empty()){
        int a=qx.front(); qx.pop();
        int b=qy.front(); qy.pop();
        for(int i=0;i<8;i++){
            int xx=a+dx[i],yy=b+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]==ch){
                qx.push(xx); qy.push(yy);
                tmp++;
                s[xx][yy]='0';
            }
        }
    }
    return;
}

int main(){
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        lo=no=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]!='0'){
                    no++;
                    bfs(i,j);
                    lo=max(tmp,lo);
                }
            }
        }
        cout<<(lo>=no?"peace\n":"choas\n");
    }
}
