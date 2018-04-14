#include <bits/stdc++.h>
using namespace std;
#define N 105
#define D(i,j) s[i][j]=='X'?0:s[i][j]-'0'
int main(){
	int n,dp[N][N];
	bool vis[N][N];
	string s[N];
	cin>>n;
	memset(vis,0,sizeof(vis));
	for(int ni=0;ni<n;ni++) cin>>s[ni];	
	for(int ni=0;ni<n;ni++){
		dp[i][0]=D(i,j);
		if(dp[i][j])vis[i][j]=1;
		if(i&&vis[])
	}
	for(int ni=0;ni<n;ni++) cin>>s[ni];
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(dp[i-1][j]||dp[i][j-1]){
				dp[i][j]=D(i,j);
				vis[i][j]=1;
				dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	if(vis[n-1][n-1])
		cout<<dp[n-1][n-1]<<endl;
	else
		cout<<"X\n";
}
