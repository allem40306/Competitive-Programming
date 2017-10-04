#include <iostream>
using namespace std;
const int N=10005;
int main(){
	freopen("c240_00.in","r",stdin);
	freopen("c240_00.out","w",stdout);
	int n,w,a[N],b[N],dp[N],ans;
	while(cin>>n>>w){
		for(int i=0;i<N;i++){
			dp[i]=0;
		}
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=0;i<n;i++){
			for(int j=w;j-b[i]>=0;j--){
				if((dp[j-b[i]]||j-b[i]==0)&&(dp[j]<dp[j-b[i]]+a[i]))
					dp[j]=dp[j-b[i]]+a[i];
			}
		}
		for(int i=w;i;i--){
			if(ans<dp[i])ans=dp[i];
		}
		cout<<ans<<'\n';
	}
}
