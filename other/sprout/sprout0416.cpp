#include <iostream>
#include <cmath>
using namespace std;
const int N=2005;
const long long mod=1000000007;
int main(){
	long long n,a,b,k,dp[N][N],sum[N][N];
	cin>>n>>a>>b>>k;
	dp[0][a]=1;
	for(int i=0;i<=n;i++){
		dp[0][i]=(i==a?1:0);
		sum[0][i]=(i>=a?1:0);
	}
	if(a>b){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j>b)dp[i][j]=(sum[i-1][n]%mod-sum[i-1][(j+b)/2]%mod-dp[i-1][j]%mod+mod)%mod;
				sum[i][j]=(sum[i][j-1]%mod+dp[i][j]%mod+mod)%mod;
			}
		}
	}else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j<b)dp[i][j]=(sum[i-1][(j+b+1)/2-1]%mod-sum[i-1][0]%mod-dp[i-1][j]%mod+mod)%mod;
				sum[i][j]=(sum[i][j-1]%mod+dp[i][j]%mod+mod)%mod;
			}
		}
	}
//	for(int i=0;i<=k;i++){
//		for(int j=0;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}cout<<'\n';
//	}
	cout<<sum[k][n]<<'\n';
}
