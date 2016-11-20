#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 256
int a[N][N],m,n;
bool vis[N][N];
	
void f(int i,int j){
	vis[i][j]=1;
	queue <int> q;
}

int main(){
	while(scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++)
			for(int j=0;j<m;j++){
				if(a[i][j]&&!vis[i][j]){
					f(i,j);
				}
			}
	}
}
