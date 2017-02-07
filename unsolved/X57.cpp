#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long t,ti=0,n,m;
	for(cin>>t;ti<t;ti++){
		cin>>n;
		if(n<=2)
			cout<<n<<endl;
		else if(n%2)
			cout<<n*(n-1)*(n-2)<<endl;
		else if(n%3)
			cout<<n*(n-1)*(n-3)<<endl;
		else 
			cout<<n*(n-1)*(n-5)<<endl;
	}
}
