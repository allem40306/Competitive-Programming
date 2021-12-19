#include <iostream>
#include <cmath> 
using namespace std;
#define N 10005
long long t,ti,n,m,k,a,b,dp[N];
void init(){
	cin>>n>>m;
	for(int i=0;i<N;i++){
		dp[i]=m+1;
		dp[0]=0;
	}
}
int main(){
	cin.tie(NULL);
	for(cin>>t;ti<t;ti++){
		init();
		for(int i=0;i<n;i++){
			cin>>a>>b;
			for(int j=N-1;j-b>=0;j--){
				if((j-b==0||dp[j-b]<=m)&&dp[j-b]+a<=m){
					dp[j]=min(dp[j],dp[j-b]+a);
//					cout<<j<<' '<<dp[j]<<'\n';
				}
			}
		}
		for(int i=N-1;i>=0;i--){
			if(dp[i]<=m){
				cout<<i<<'\n';
				break;
			}
		}
	}
}
