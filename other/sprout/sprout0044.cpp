#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define N 105
#define X k.x+dx[i]
#define Y k.y+dy[i]
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
};
int main(){
	cin.tie(NULL);
	int n,m,step[N][N];
	string s[N];
	queue<loc>q,r;
	loc k=loc(0,0);
	while(cin>>n,n){
		memset(step,-1,sizeof(step));
		while(q.size())q.pop();
		for(int i=0;i<n;i++)
			cin>>s[i];
		m=s[0].size();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='K'){
					q.push(loc(i,j));
					step[i][j]=0;
				}else if(s[i][j]=='@')
					r.push(loc(i,j));
			}
		}
		while(q.size()){
			k=q.front(); q.pop();
			for(int i=0;i<4;i++){
				if(X>=0&&X<n&&Y>=0&&Y<m&&step[X][Y]==-1&&s[X][Y]!='#'){
					step[X][Y]=step[k.x][k.y]+1;
					q.push(loc(X,Y));
				}
			}
		}
		int ans=100000;
		while(r.size()){
			if(step[r.front().x][r.front().y]!=-1)
				ans=min(step[r.front().x][r.front().y],ans);
			r.pop();
		}
		if(ans!=100000)
			cout<<ans<<'\n';
		else
			cout<<"= =\"\n";
	}
}
