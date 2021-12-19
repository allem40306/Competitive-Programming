#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define N 1005
#define X k.x+dx[i]
#define Y k.y+dy[i]
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
}k=loc(0,0);
int t,h,w,ti,j,ans;
bool vis[N][N];
string s[N];
queue<loc>q;
int main(){
	cin.tie(NULL);
	for(cin>>t;ti<t;ti++){
		for(cin>>h>>w,j=0;j<h;j++)
			cin>>s[j];
		ans=0;
		for(int a=0;a<h;a++){
			for(int b=0;b<w;b++){
				if(s[a][b]=='.'){
					s[a][b]='#';
					ans++;
					while(q.size())q.pop();
					q.push(loc(a,b));
					while(q.size()){
						k=q.front(); q.pop();
						for(int i=0;i<4;i++){
							if(X>=0&&X<=h&&Y>=0&&Y<=w&&s[X][Y]=='.'){
								s[X][Y]='#';
								q.push(loc(X,Y));
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
