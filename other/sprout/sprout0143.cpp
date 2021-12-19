#include <iostream>
#include <cstring>
using namespace std;
#define N 105
int t,ti,n,arr[N],dp[N][N];
int main(){
	for(cin>>t,ti=0;ti<t;ti++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				dp[i][j]=10000005;
			}
		}
		cin>>n;
		arr[0]=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			dp[i][i]=0;
			arr[i]+=arr[i-1];
		}
		for(int i=1;i<n;i++){
			for(int j=1;i+j<=n;j++){
				for(int k=j;k<i+j;k++){
					dp[j][i+j]=min((j!=k)*dp[j][k]+(k+1!=i+j)*dp[k+1][i+j]+arr[i+j]-arr[j-1],dp[j][i+j]);
				}
			}
		}
		cout<<dp[1][n]<<'\n';
	}
}
