#include <iostream>
#include <cstring>
using namespace std;
#define N 100005
int main(){
	cin.tie(NULL);
	int t,ti=0,n,m,a[N],dp[N][2];
	for(cin>>t;ti<t;ti++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
			dp[i][0]=dp[i][1]=0;
		}
		int ans=0;
		for(int i=0,j;i<n;i++){
			if(a[i]>=m){
				dp[i][0]=1;
				for(j=i-1;j>=0;j--){
					if(a[i]>=a[j])dp[i][0]=max(dp[i][0],dp[j][0]+1);
					if(a[i]>=a[j]*2)dp[i][0]=max(dp[i][0],dp[j][1]+1);
				}
			}
			if(a[i]*2>=m){
				dp[i][1]=1;
				for(j=i-1;j>=0;j--){
					if(a[i]*2>=a[j])dp[i][1]=max(dp[i][0],dp[j][0]+1);
					if(a[i]*2>=a[j]*2)dp[i][1]=max(dp[i][0],dp[j][1]+1);
				}
			}
			ans=max(ans,max(dp[i][0],dp[i][1]));
		}
		cout<<ans<<'\n';
	}
}
