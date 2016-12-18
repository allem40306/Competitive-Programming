#include <iostream>
#include <cstring>
int arr[5][5],n,w,l,e;
bool vis [5][5];
void dfs(int v,int p,int a,int b){
	//printf("%d %d %d %d\n",v,p,a,b);
	bool bb=0;
	if(p==0){
		for(int i=0;i<n;i++)
			if(!vis[v][i]){
				vis[v][i]=bb=1;
				dfs(i,!p,a+arr[v][i],b);
				vis[v][i]=0;
			}
	}else{
		for(int i=0;i<n;i++)	
			if(!vis[i][v]){
				vis[i][v]=bb=1;
				dfs(i,!p,a,b+arr[i][v]);
				vis[i][v]=0;
			}
		}
	if(!bb)a>b?w++:a<b?l++:e++;	
	return;
}

int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
		w=l=e=0; memset(vis,0,sizeof(vis));
		dfs(0,0,0,0);
		printf("%d %d %d\n",w,l,e);
	}
}
