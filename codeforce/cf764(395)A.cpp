#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	int t;
	if(a<b)t=a,a=b,b=t;
	while(t=a%b)a=b,b=t;
	return b;
}
int main(){
	long long n,m,z;
	cin>>n>>m>>z;
	cout<<z/(n*m/gcd(n,m))<<endl;
}
