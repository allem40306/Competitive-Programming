#include <iostream>
#include <algorithm>
using namespace std;
const int N=20;
bool b[N];
int t,ti=0,n,dis[N][N],dp[N][100000];
int btb(){
	int out=0;
	for(int i=0,j=1;i<n;i++,j*=2)
		out+=b[i]*j;
	return out;
}
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<100000;j++){
			dp[i][j]=0;
		}
	}
}
int gcd(int i,int j){
	int k;
	while(j%i){
		k=j%i;
		j=i;
		i=k;
	}
	return i;
}
int main(){
	freopen("c239_02.in","r",stdin); 
	freopen("c239_02.out","w",stdout);
	cin.tie(NULL);
	while(cin>>n){
		init();
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cin>>dis[i][j];
				dis[j][i]=dis[i][j];
			}
		}
		int a1=100000,a2=0,a3;
		for(int i=1,j;i<=n;i++){
			for(int jj=0;jj<n;jj++){
				b[n-jj-1]=(jj<i);
			}
			do{
				j=btb();
	//				cout<<j<<'\n';
				for(int x=0;x<n;x++){
					if(!b[x])continue;
					if(i==1)dp[x][j]=dis[x][0];
					for(int y=0;y<n;y++){
						if(x!=y&&b[y]){
							if(dp[x][j]==0||dp[x][j]>dp[y][j-(1<<x)]+dis[y][x])
								dp[x][j]=dp[y][j-(1<<x)]+dis[y][x];
	//							cout<<x<<' '<<y<<' '<<j<<' '<<dp[y][j-(1<<x)]<<' '<<dp[x][j]<<'\n';
						}
					}
				}
			}while(next_permutation(b,b+n));
		}
		a1=dp[0][(1<<n)-1];
		init();
		for(int i=1,j;i<=n;i++){
			for(int jj=0;jj<n;jj++){
				b[n-jj-1]=(jj<i);
			}
			do{
				j=btb();
	//				cout<<j<<'\n';
				for(int x=0;x<n;x++){
					if(!b[x])continue;
					if(i==1)dp[x][j]=dis[x][0];
					for(int y=0;y<n;y++){
						if(x!=y&&b[y]){
							if(dp[x][j]==0||dp[x][j]<dp[y][j-(1<<x)]+dis[y][x])
								dp[x][j]=dp[y][j-(1<<x)]+dis[y][x];
								a2=max(a2,dp[x][j]);
	//							cout<<x<<' '<<y<<' '<<j<<' '<<dp[y][j-(1<<x)]<<' '<<dp[x][j]<<'\n';
						}
					}
				}
			}while(next_permutation(b,b+n));
		}
		a2=dp[0][(1<<n)-1];
		if(a2%a1==0)
			cout<<a2/a1<<'\n';
		else{
			a3=gcd(a1,a2);
			cout<<a2/a3<<'/'<<a1/a3<<'\n';
		}
	}	
}
