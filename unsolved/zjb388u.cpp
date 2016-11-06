#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005

int main() {
	int n,a[N],dp[N];
	while(scanf("%d",&n)!=EOF){
		if(n<2){
			if(n)scanf("%d",&n);
			printf("0\n");	
		}else{
			for(int ni=0;ni<n;ni++)scanf("%d",&a[ni]);
			memset(dp,0,sizeof(dp));
			for(int i=1;i<n;i++)
					dp[i]=std::min(dp[i-1]+std::abs(a[i]-a[i-1]),dp[i-2]+std::abs(a[i]-a[i-2])); 	
			printf("%d\n",dp[n-1]);
		}
	}
}	
