#include <bits/stdc++.h>
using namespace std;
const int N=55;

int gcd(int a,int b){
	int t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	while(t=a%b){
		a=b;
		b=t;
	}
	return b;
}

int main(){
	int n,m,a[N];
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		m=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(gcd(a[i],a[j])==1)m++;
			}
		}
		if(m)cout<<fixed<<setprecision(6)<<sqrt(3*n*(n-1)*1.0/m)<<'\n';
		else cout<<"No estimate for this data set.\n";
	}
} 
