#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define X j-kk*a[i][0]
long long t,n,f,k,a[N][2],b[N],br,dp[N];
int main(){
    cin>>t>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i][0];
    for(int i=0;i<n;i++)cin>>a[i][1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
    	br=1;
    	do{
    		b[br]=b[br-1]+a[i][1];
    		br++;
		}while(a[i][1]/=2);
		for(int j=t;j>=0;j--){
			for(int kk=1;b[kk]&&kk<=k&&X>=0;kk++){
				if(dp[X]||X==0){
					dp[j]=max(dp[X]+b[kk],dp[j]);
				}
			}
		}
	}
	long long ans=0;
	for(int i=0;i<t;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
} 
