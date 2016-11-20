#include <iostream>
#include <cstring>
using namespace std;
#define N 200
#define M 2000

int main(){
	int t,ti=0;
	for(cin>>t;ti<t;ti++){
		int n,p,sum=0,a[N];
		bool dp[M];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		cin>>n>>p;
		for(int i=0;i<p;i++){cin>>a[i];sum+=a[i];}
		for(int i=0;i<p;i++){
			for(int j=M-1;j-a[i]>=0;j--)
				if(dp[j-a[i]])dp[j]=1;
		}
		cout<<(dp[n]?"YES\n":"NO\n");
	}
}
