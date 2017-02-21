#include <bits/stdc++.h>
using namespace std;

int mex(int n,int k){
	if(!n)return 0;
	if(k==1){
		return n>4?(n%2?0:(mex(n/2,k)==1?2:1)):n==4?2:n%2;
	}else{
		return n<3?n:1-n%2;
	}
}

int main(){
	int n,k,x,r;
	cin>>n>>k>>r;
	k%=2;
	r=mex(r,k);
	for(;n>1;n--){
		cin>>x;
		r^=mex(x,k);
	}
	if(r)cout<<"Kevin\n";
	else cout<<"Nicky\n";
}
