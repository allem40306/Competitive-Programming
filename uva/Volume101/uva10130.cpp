#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int t,n,p,w,g,sum,dp[100005],ans;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>p>>w;
			sum+=w;
			for(int j=sum;j-w>=0;j--){
				dp[j]=max(dp[j],dp[j-w]+p);
			}
		}
		ans=0;
		cin>>g;
		for(int i=0;i<g;i++){
			cin>>w;
			ans+=*max_element(dp,dp+w+1);
		}
		cout<<ans<<'\n';
	}
}
