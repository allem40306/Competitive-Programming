#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define N 8
#define M 1005
struct loc{
	int c,x,y,t;
	loc(int c,int x,int y,int t):c(c),x(x),y(y),t(t){}
}k=loc(0,0,0,0);
int nc[M][M],cans[M],aa,t,ti,n,x,y;
char ch;
queue<loc>q;
string s=".RYBOPGD";
void init(){
	memset(cans,0,sizeof(cans));
	memset(nc,0,sizeof(nc));
	cin>>n;
	while(q.size())q.pop();
	for(int i=0;i<3;i++){
		cin>>ch>>x>>y;
		q.push(loc(s.find(ch),x,y,0));
	}
	cin>>ch; aa=s.find(ch);
	for(int i=0;i<3;i++){
		k=q.front();q.pop();
		if(k.c==aa){
			cans[1]++;
			nc[k.x][k.y]=aa;
		}
		q.push(k);
	}
}
int Dye[N][N]={0,1,2,3,4,5,6,7,1,1,4,5,4,5,7,7,2,4,2,6,4,7,6,7,3,5,6,3,7,5,6,7,4,4,4,7,4,7,7,7,5,5,7,5,7,5,7,7,6,7,6,6,7,7,6,7,7,7,7,7,7,7,7,7};
int main(){
//	freopen("text.txt","w",stdout);
	cin.tie(NULL);
	int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1},kx,ky,dye;
	cin.tie(NULL);
		for(cin>>t,ti=0;ti<t;ti++){
		init();
		while(q.size()){
			k=q.front(),q.pop();
			for(int i=0;i<8;i++){
				kx=k.x+dx[i],ky=k.y+dy[i]; 
				if(kx<0||kx>=n||ky<0||ky>=n)continue;
				dye=Dye[nc[kx][ky]][k.c];
				if(dye>nc[kx][ky]){
//					cout<<nc[kx][ky]<<' '<<k.c<<' '<<dye<<'\n';
					q.push(loc(dye,kx,ky,k.t+1));
					if(nc[kx][ky]!=aa&&dye==aa)cans[k.t+1]++;
					else if(nc[kx][ky]==aa&&dye!=aa)cans[k.t+1]--;
					nc[kx][ky]=dye;
				}
			}
		}
		int tans=0,ans=0;
		for(int i=0;i<M;i++){
			tans+=cans[i];
			ans=max(ans,tans);
		}
		cout<<ans<<'\n';
	}
}
