#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m,o;
int main(){
	cin>>n>>m;
	o=n;
	if(n*2<m){
		n+=(m-2*o)/4;
		m-=(m-2*o)/4*2;
	}
	cout<<min(n,m/2)<<endl;
}
