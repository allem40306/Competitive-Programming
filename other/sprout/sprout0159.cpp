#include <iostream>
using namespace std;
const int N=20005;
int main(){
	int t,ti,n,m,c[N],k[N],co;
	for(cin>>t,ti=0;ti<t;ti++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>c[i]>>k[i];
		}
		bool dp[N]={};
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;k[i]>0;k[i]-=j,j*=2){
				co=(j<=k[i]?j:k[i]);
				for(int kk=m;kk-co*c[i]>=0;kk--){
					if(dp[kk-co*c[i]])dp[kk]=1;
				}
			}
		}
		if(dp[m])cout<<"Yes\n";
		else cout<<"No\n";
	}
} 
