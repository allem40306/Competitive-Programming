#include <iostream>
#include <cstring>
using namespace std;
int vis[20][20],cur[20],x,y,c;//0 x 1 \ 2 / c:caculate

void dfs(int n){
	if(n==9){
		if(c/10==0)cout<<' ';
		cout<<c++<<"     ";
		for(int i=1;i<=8;i++){
			cout<<' '<<cur[i];
		}
		cout<<'\n';
		return;
	}if(n==y){
		dfs(n+1);
	}else{
		for(int i=1;i<=8;i++){
			if(!vis[0][i]&&!vis[1][i-n+8]&&!vis[2][i+n]){
				cur[n]=i;
				vis[0][i]=vis[1][i-n+8]=vis[2][i+n]=1;
				dfs(n+1);
				vis[0][i]=vis[1][i-n+8]=vis[2][i+n]=0;
			}
		}
	}
	return;
}

int main(){
	int n;
//	freopen("ooo.txt","w",stdout);
	for(cin>>n;n;n--){
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		c=1;
		vis[0][x]=vis[1][x-y+8]=vis[2][x+y]=1;
		cur[y]=x;
		cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		dfs(1);
		if(n>1)cout<<'\n';
	}
}
//11 12 13
//21 22 23
//31 32 33