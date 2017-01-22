#include <iostream>
#include <cstring>
int main() {
	int aa[105][105],n,m,a,b,c,d;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(aa,0,sizeof(aa));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&aa[i][j]);
				aa[i][j]=aa[i][j]+aa[i][j-1]+aa[i-1][j]-aa[i-1][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d  ",aa[i][j]);
			}
			printf("\n");
		}
		for(int k=0;k<m;k++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			printf("%d\n",aa[c][d]-aa[a][b]+1);
		}
	}
}
