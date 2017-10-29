#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,h=0,ans,a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>h){
			h=a;
			ans=a+b;
		}
	}
	cout<<ans<<'\n';
}
