#include <bits/stdc++.h>
using namespace std;
int nx,ny;
struct loc{
	int x,y,p;
	loc(int x,int y,int p):x(x),y(y),p(p){
	}
};
bool cmp(loc a,loc b){
	if(a.p!=b.p)return a.p>b.p;
	if((a.x-nx)*(a.x-nx)+(a.y-ny)*(a.y-ny)!=(b.x-nx)*(b.x-nx)+(b.y-ny)*(b.y-ny))
		return (a.x-nx)*(a.x-nx)+(a.y-ny)*(a.y-ny)<(b.x-nx)*(b.x-nx)+(b.y-ny)*(b.y-ny);
	return a.x!=b.x?(a.x<b.x):(a.y<b.y);
}
struct ans{
	int x,y;
	ans(int x,int y):x(x),y(y){
	}
};
int main(){
	int n,m,ai=0,k,st=0;
	loc a[500]=loc(0,0,0);
	nx=ny=0;
	queue<ans>q;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>k;
			if(k){
				a[ai++]=loc(i,j,k);
			}
		}
	}
	q.push(ans(0,0));
	for(int i=0;i!=ai;i++){
		sort(a+i,a+ai,cmp);
		q.push(ans(a[i].x,a[i].y));
		st+=abs(a[i].x-nx)+abs(a[i].y-ny);
		nx=a[i].x;
		ny=a[i].y;
	}
	st+=abs((n-1)-nx)+abs((m-1)-ny);
	q.push(ans(n-1,m-1));
	cout<<st<<'\n';
	while(q.size()){
		cout<<'('<<q.front().x<<','<<q.front().y<<')';
		q.pop();
	}
	cout<<'\n';
}
