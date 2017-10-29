#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long n;
	cin>>n;
	for(unsigned long long i=1;i<=3500;i++){
		for(unsigned long long j=i;j<=3500;j++){
			for(unsigned long long k=j;k<=3500;k++){
				if(4*i*j*k==n*(i+j+k)){
					cout<<i<<' '<<j<<' '<<k<<'\n';
				}
			}
		}
	}
}
