#include <bits/stdc++.h>
using namespace std;

int sos(int n){
	int sum=0;
	while(n){
		sum+=(n%10)*(n%10);
		n/=10;
	}
	return sum;
}

int main(){
	int t,n;
	bitset<1000>b;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		bool ok=0;
		b.reset();
		cin>>n;
		int nn=sos(n);
		while(!b[nn]){
			b[nn]=1;
			if(nn==1)ok=1;
			nn=sos(nn);
		}
		if(ok){
			cout<<"Case #"<<ti<<": "<<n<<" is a Happy number.\n";
		}else {
			cout<<"Case #"<<ti<<": "<<n<<" is an Unhappy number.\n";
		}
	}
}
