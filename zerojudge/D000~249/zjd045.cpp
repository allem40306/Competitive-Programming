#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005
#define M 3
#define MAX(x,y) x>y?x:y
int main(){
	int n,ni=1,i,j,k,a[M][N],b[N],c[M][2],ans;
	for(scanf("%d",&n);ni<=n;ni++){
		printf("Case #%d:\n",ni);
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		for(i=0;i<M&&(scanf("%d",&c[i][0]));i++)
			for(j=0;j<c[i][0];j++)scanf("%d",&a[i][j]),b[a[i][j]]++;
		for(i=ans=0;i<M;ans=MAX(ans,c[i][0]),i++)
		for(j=0,c[i][1]=c[i][0];j<c[i][1];j++)if(b[a[i][j]]!=1)c[i][0]--;
		//printf("%d %d %d\n",c[0][0],c[1][0],c[2][0]);
		for(int i=0;i<M;i++)if(c[i][0]==ans){
			std::sort(a[i],a[i]+c[i][1]);
			for(j=0,printf("%d %d",i+1,c[i][0]);j<c[i][1];j++)if(b[a[i][j]]==1)printf(" %d",a[i][j]);
			printf("\n");
		}
	}
}
