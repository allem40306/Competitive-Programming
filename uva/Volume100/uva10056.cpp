#include <bits/stdc++.h>
using namespace std;

int main(){
	int s,n,k;
	double p;
	cin>>s;
	while(s--){
		cin>>n>>p>>k;
		if(p==0.0){
			cout<<"0.0000\n";
			continue;
		}
		cout<<fixed<<setprecision(4)<< p * pow(1-p, k-1) / (1 - pow(1-p, n)) <<'\n';
	}
}
