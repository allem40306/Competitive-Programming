
#include <bits/stdc++.h>
using namespace std;
int t,a,b,k,dp[15][105][105],n,d[15],r;

void tra(int x){
	n=0;
	while(x){
		d[++n]=x%10;
		x/=10;
	}
	for(int i=1;i<=n/2;i++){
		r=d[i];
		d[i]=d[n+1-i];
		d[n+1-i]=r;
	}
}

int sol(int x){
//	cout<<x<<'\n';
	if(!x)return 1;
	tra(x);
	memset(dp,0,sizeof(dp));
	int x1=0,x2=0;
	for(int i=1;i<=n;i++){
		for(int a=0;a<k;a++){
			for(int b=0;b<k;b++){
				for(int j=0;j<=9;j++){
//					cout<<i<<' '<<(a*10+b)%k<<' '<<(b+j)%k<<'\n';
					dp[i][(a*10+j)%k][(b+j)%k]+=dp[i-1][a][b];
				}
			}
		}
//		cout<<i<<' '<<d[i]<<'\n';
		for(int j=0;j<d[i];j++){
			dp[i][(x1*10+j)%k][(x2+j)%k]++;
//			cout<<i<<' '<<(x1*10+j)%k<<' '<<(x2+j)%k<<'\n';
//			cout<<dp[i][(x1*10+j)%k][(x2+j)%k]<<'\n';
		}
		x1=(x1*10+d[i])%k;
		x2=(x2+d[i])%k;
	}
	if(x1==0&&x2==0){
		dp[n][0][0]++;
	}
	return dp[n][0][0];
}

int main(){
//	freopen("text.txt","w",stdout);
	cin>>t;
	while(t--){
		cin>>a>>b>>k;
		if(k>100)cout<<0<<'\n';
		else cout<<sol(b)-sol(a-1)<<'\n';
	}
}
