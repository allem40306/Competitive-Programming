#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long a[15][15],s[15][15],n,m;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			a[i][j]=pow(j,i)*pow(10,i-1);
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	while(cin>>n>>m){
		cout<<s[n][m]<<'\n';
	}
}
