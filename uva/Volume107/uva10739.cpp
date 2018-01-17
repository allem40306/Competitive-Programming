#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int t,dp[N][N];

int main(){
//	freopen("10739.txt","w",stdout);
	string s;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>s;
		memset(dp,0,sizeof(dp));
		for(int j=0;j<s.size();j++){
			for(int i=j;i>=0;i--){
				if(s[i]==s[j]){
					dp[i][j]=dp[i+1][j-1];
				}else{
					dp[i][j]=min(dp[i+1][j-1],min(dp[i][j-1],dp[i+1][j]))+1;
				}
			}	
		}
		cout<<"Case "<<ti<<": "<<dp[0][s.size()-1]<<'\n';
	}
}
