#include <iostream>
using namespace std;
#define Max(x,y) x>y?x:y
#define N 40
 
int main() {
	int n,arr[N],dp[N];
	while(scanf("%d",&n)&&n){
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);	
			dp[i]=arr[i];
		}
		for(int i=1;i<n;i++)
			dp[i]=Max(arr[i-1]*2,arr[i-1]+arr[i]*2);
		for(int i=0;i<n;i++)
			ans=Max(ans,dp[i]);
			printf("%d\n",ans);
	}
}
