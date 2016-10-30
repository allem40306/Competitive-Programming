#include <cstdio>
#define N 26

int main(){
	int dp[N]={1,1,2},n;
	for(int i=3;i<N;i++)
		dp[i]=dp[i-3]*4+dp[i-2]+dp[i-1];
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",dp[n]);
}
