#include <bits/stdc++.h>
using namespace std;
#define N 1005
int t,i=1,k,n;
struct pc{
	double r,h;
}arr[N];
int main(){
	freopen("A-small-attempt1.out","w",stdout);
	cin.tie(NULL);
	double dp[N][2];
	for(cin>>t;i<=t;i++){
		cin>>k>>n;
		memset(dp,0,sizeof(dp));
		for(int j=0;j<k;j++){
			cin>>arr[j].r>>arr[j].h;
		}
		for(int j=0;j<k;j++){
			for(int jj=j+1;jj>0;jj--){
				if(arr[j].r*arr[j].r+2*arr[j].r*arr[j].h+dp[jj-1][0]-dp[jj-1][1]*dp[jj-1][1]>dp[jj][0]){
					dp[jj][0]=max(arr[j].r,dp[jj-1][1])*max(arr[j].r,dp[jj-1][1])+2*arr[j].r*arr[j].h+dp[jj-1][0]-dp[jj-1][1]*dp[jj-1][1];
//					cout<<max(arr[j].r,dp[jj][1])*max(arr[j].r,dp[jj][1])<<' '<<2*arr[j].r*arr[j].h<<' '<<dp[jj-1][0]<<' '<<dp[jj-1][1]*dp[jj-1][1]<<'\n';
					dp[jj][1]=max(arr[j].r,dp[jj-1][1]);
				}
//				cout<<dp[jj][0]<<'\n';
			}
		}
		cout<<fixed<<setprecision(9)<<"Case #"<<i<<": "<<dp[n][0]*acos(-1.0)<<'\n';
	}
}
