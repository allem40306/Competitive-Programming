#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sol(LL a,LL b){
	LL r=a+b;
	LL ans=(1+r)*r/2;
	return ans+1+a;
}

int main() {
	LL t, a, b, c, d;
	cin >> t;
	for (LL ti = 1; ti <= t; ti++) {
		cin>>a>>b>>c>>d;
		cout<<"Case "<<ti<<": "<<sol(c,d)-sol(a,b)<<'\n';
	}
}