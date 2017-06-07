#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	int n,i=0,a,b,ans=1;
	for(cin>>n>>a;i<n-1;i++){
		cin>>b;
		if(a!=b){
			a=b;
			ans++;
		}
	} 
	cout<<ans<<'\n';
}
