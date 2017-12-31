#include <bits/stdc++.h>
using namespace std;
string s="CDHS";
const int N=60;
int main(){
	int n,m,a[N],si,x;
	char ch;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ch>>x;
		for(si=0;s[si]!=ch;si++);
		a[i]=si+4*x;
//		cout<<a[i]<<'\n';
	}
	sort(a,a+n);
	cin>>m;
	m=n-m;
	cout<<s[a[m]%4]<<' '<<a[m]/4<<'\n';
}
