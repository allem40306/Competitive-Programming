#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 256
int a[N][N],x,y;
bool vis[N][N];
int w,e,n,s,aa;
int dx[8]={-1,0,1,-1,1,-1,0,1},dy[8]={-1,-1,-1,0,0,1,1,1};

struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
	loc(){}
};

void update(int i,int j){
	w=(w<j?w:j);
	e=(e>j?e:j);
	n=(n<i?n:i);
	s=(s>i?s:i);
	aa++;
}

void f(int i,int j){
	w=n=257; e=s=-1; aa=0;
	vis[i][j]=1;
	queue <loc> q;
	q.push(loc(i,j));
	while(q.size()){
		loc k=q.front(); q.pop();
		update(k.x,k.y);
		for(int di=0;di<8;di++){
			int kx=k.x+dx[di],ky=k.y+dy[di];
			if(kx>=0&&ky>=0&&kx<x&&ky<y&&!vis[kx][ky]&&a[kx][ky]){
				vis[kx][ky]=1; q.push(loc(kx,ky));
			}
		}
	}
}

int main(){
	while(scanf("%d %d",&x,&y)!=EOF){
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				scanf("%d",&a[i][j]);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++){
				if(a[i][j]&&!vis[i][j]){
					f(i,j);
					printf("%d %d %d %d %d\n",w,n,e,s,aa);
				}
			}
	}
}
