#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n,m;
	while(cin>>n>>m){
		LL ans=0,k=1,kk,tar;
		while(k<=n){
			tar=k*m/n;
			kk=tar*n/m;
			ans+=tar*(kk-k+1);
			k=kk+1;
		}
		cout<<ans<<'\n';
	}
}
