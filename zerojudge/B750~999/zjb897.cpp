#include <bits/stdc++.h>
using namespace std;

int main(){
	double n,k;
	while(cin>>n>>k){
		cout<<(int)((lgamma(n+1)-lgamma(k+1)-lgamma(n-k+1))/log(10)+1)<<endl;
	}
}
