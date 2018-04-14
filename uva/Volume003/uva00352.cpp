#include <bits/stdc++.h>
using namespace std;
const int N=30;
int dx[8]={-1,0,1,-1,1,-1,0,1},dy[8]={-1,-1,-1,0,0,1,1,1};
struct Loc{
    int x,y;
    Loc(){};
    Loc(int x,int y):x(x),y(y){}
};
int main(){
    int n,ti=1,ans;
    Loc k;
    queue<Loc>q;
    string s[N];
    while(cin>>n){
        ans=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='1'){
                    ans++;
                    int xx,yy;
                    q.push(Loc(i,j));
                    while(!q.empty()){
                        k=q.front(); q.pop();
                        s[k.x][k.y]='0';
                        for(int a=0;a<8;a++){
                            xx=k.x+dx[a];
                            yy=k.y+dy[a];
                            if(xx<0||xx>=n||yy<0||yy>=n||s[xx][yy]=='0')continue;
                            q.push(Loc(xx,yy));
                        }
                    }
                }
            }
        }
        cout<<"Image number "<<ti++<<" contains "<<ans<<" war eagles.\n";
    }
}
