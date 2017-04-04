#include <iostream>
#include <cstring>
using namespace std;
#define len 2000
bool b[len][len];
void report(int ax,int ay,int bx,int by,int cx,int cy){
	Report(ax,ay,bx,by,cx,cy);
	b[ax][ay]=b[bx][by]=b[cx][cy]=1;
//	cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<' '<<cx<<' '<<cy<<'\n';
	return;
}
void dnc(int ax,int ay,int bx,int by,int x,int y){
//	cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<'\n';
	int L=bx-ax+1;
	if(L==2){
		if(b[ax][ay])report(ax+1,ay,ax,ay+1,ax+1,ay+1);
		else if(b[ax+1][ay])report(ax,ay,ax,ay+1,ax+1,ay+1);
		else if(b[ax][ay+1])report(ax+1,ay,ax,ay,ax+1,ay+1);
		else if(b[ax+1][ay+1])report(ax+1,ay,ax,ay+1,ax,ay);
		return;
	}
	int cx=(ax+bx)/2,cy=(ay+by)/2;//medium
//	cout<<cx<<' '<<cy<<'\n';
	if(x<=cx&&y<=cy){
		report(cx+1,cy,cx,cy+1,cx+1,cy+1);
		dnc(ax,ay,cx,cy,x,y);
		dnc(cx+1,ay,bx,cy,cx+1,cy);
		dnc(ax,cy+1,cx,by,cx,cy+1);
		dnc(cx+1,cy+1,bx,by,cx+1,cy+1);
	}
	else if(!x<=cx&&y<=cy){
		report(cx,cy,cx,cy+1,cx+1,cy+1);
		dnc(ax,ay,cx,cy,cx,cy);
		dnc(cx+1,ay,bx,cy,x,y);
		dnc(ax,cy+1,cx,by,cx,cy+1);
		dnc(cx+1,cy+1,bx,by,cx+1,cy+1);
	}
	else if(x<=cx&&!y<=cy){
		report(cx+1,cy,cx,cy,cx+1,cy+1);
		dnc(ax,ay,cx,cy,cx,cy);
		dnc(cx+1,ay,bx,cy,cx+1,cy);
		dnc(ax,cy+1,cx,by,x,y);
		dnc(cx+1,cy+1,bx,by,cx+1,cy+1);
	}
	else if(!x<=cx&&!y<=cy){
		report(cx+1,cy,cx,cy+1,cx,cy);
		dnc(ax,ay,cx,cy,cx,cy);
		dnc(cx+1,ay,bx,cy,cx+1,cy);
		dnc(ax,cy+1,cx,by,cx,cy+1);
		dnc(cx+1,cy+1,bx,by,x,y);
	}
	return;
}
void solve(int N,int X,int Y){
	memset(b,0,sizeof(b));
	b[X][Y]=1;
	dnc(1,1,N,N,X,Y);
}
//int main(){
//	freopen("gogo.txt","w",stdout);
//	int n,x,y;
//	cin>>n>>x>>y;
//	solve(n,x,y);
//}
