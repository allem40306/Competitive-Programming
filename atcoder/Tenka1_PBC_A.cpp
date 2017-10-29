#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin>>s){
		int ans=0;
		for(int i=0;i<6;i++){
			ans+=(s[i]=='1');
		}
		cout<<ans<<'\n';
	}
}
