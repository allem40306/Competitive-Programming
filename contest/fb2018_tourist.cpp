#include <bits/stdc++.h>
using namespace std;
int main() {
	long long t, n, k, v;
	string s[100];
	cin>>t;
	for(long long ti=1;ti<=t;ti++){
		cin>>n>>k>>v;
		v--;
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		cout<<"Case #"<<ti<<':';
		for(int i=0;i<k;i++){
			cout<<' '<<s[(v+i)%n];
		}
		cout<<'\n';
	}
}