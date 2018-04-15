#include <cstdio>
#include <cstring>
#define N 20
int n,m,po[N],last[N],i,j;
bool qq[N][N],vis[N],b;

void dfs(int n,int m){
	if(n==m){
		b=1;
		for(int i=0;i<n;i++){
			if(b&&last[po[i]]==i+1)continue;
			b=0;
			//printf("%d\n",po[i]);
			printf("%c",'A'+po[i]-1);
			last[po[i]]=i+1;
		}
		printf("\n");
	}else{
		for(int i=1;i<=m;i++){
			if(!vis[i]&&!qq[i][n+1]){
				po[n]=i;
				vis[i]=1;
				dfs(n+1,m);
				vis[i]=0;
			}
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(qq,0,sizeof(qq));
		memset(vis,0,sizeof(vis));		
		memset(last,-1,sizeof(last));
		for(i=1;i<=n;i++)
			while(scanf("%d",&m),m)qq[i][m]=1;
		dfs(0,n);
	}
} 
