#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,r;
	int n,m;
	while(cin>>n>>m,n||m){
		r="";
		while(n--){
			cin>>s;
			r+=s;
		}
		while(m--){
			cin>>n;
			cout<<r[n-1];
		}
		cout<<'\n';
	}
}
