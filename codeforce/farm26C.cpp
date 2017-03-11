#include <bits/stdc++.h>
using namespace std;
#define kx x+dx[i]
#define ky y+dy[i]
struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
	bool operator<(const loc& a)const{
		if(x!=a.x)
			return x<a.x;
		return 	y<a.y;
	}
	bool operator>(const loc& a)const{
		if(x!=a.x)
			return x>a.x;
		return 	y>a.y;
	}
};
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},ans=1;
string s="NSEW",r;
map<loc,int>ma;
void dfs(int x,int y){
	ma[loc(x,y)]=1;
	for(int i=0;i<4;i++){
		if(ma.find(loc(kx,ky))==ma.end()){
			cout<<s[i]<<endl;
			fflush(stdout);
			cin>>r;
			if(r[0]=='O'){
				ans++;
				ma[loc(kx,ky)]=1;
				dfs(kx,ky);
			}
		}
	}
}
int main(){
	cin>>r;
	dfs(0,0);
	cout<<"D "<<ans<<endl;
	fflush(stdout);
}
