#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,ni,a[N];
bool b[N],f=0;
int main(){
	for(cin>>n;ni<n;ni++)
		cin>>a[ni];
	for(ni=0;ni<n/2;ni++){
		b[ni]=b[n-1-ni]=f;
		f=!f;
		if(ni)cout<<' ';
		if(b[ni])cout<<a[ni];
		else cout<<a[n-1-ni]; 
	}
	for(ni=n/2;ni<n;ni++){
		cout<<' ';
		if(b[ni])cout<<a[ni];
		else cout<<a[n-1-ni];
	}
	cout<<endl;
}
