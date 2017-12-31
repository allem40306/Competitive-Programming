#include <bits/stdc++.h>
using namespace std;
const int N=15;
int main(){
	int t,n,a[N];
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<"Case "<<ti<<": "<<a[n/2]<<'\n';
	}
}
