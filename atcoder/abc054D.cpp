#include <bits/stdc++.h>
using namespace std;
#define N 40
#define M 405
int n,ma,mb,a[N],b[N],c[N],dp[M][M],ans=10000000,ans2;
int main(){
	cin>>n>>ma>>mb;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=ans;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<N;i++){
		for(int j=M;j-a[i]>=0;j--){
			for(int k=M;k-b[i]>=0;k--){
				dp[j][k]=min(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
			}
		}
	}
	ans2=ans;
	for(int i=1;i<=400;i++){
		for(int j=1;j<=400;j++){
			if(i*mb==j*ma)
				ans=min(ans,dp[i][j]);
		}
	}
	if(ans==ans2)cout<<"-1\n";
	else cout<<ans<<endl;
}
