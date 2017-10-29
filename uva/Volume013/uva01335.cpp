#include <bits/stdc++.h>
using namespace std;
const int N=150000;
int arr[N],n,al[N],ar[N];

bool ok(int x){
	int L=arr[0],R=x-L;
	al[0]=L; ar[0]=0;
	for(int i=1;i<n;i++){
		if(i&1){
			al[i]=min(L-al[i-1],arr[i]);
			ar[i]=arr[i]-al[i];
		}else{
			ar[i]=min(R-ar[i-1],arr[i]);
			al[i]=arr[i]-ar[i];
		}
	}
	return al[n-1]==0;
}

int bs(int L,int R){
	int M;
	while(L!=R){
//		cout<<L<<' '<<R<<'\n';
		M=(L+R)>>1;
		if(!ok(M)){
			L=M+1;
		}else{
			R=M;
		}
	}
	return L;
}

int main(){
	cin.tie(NULL);
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int L=arr[0],R=arr[0];
		for(int i=0;i<n;i++){
			R=max(R,arr[i]*3);
		}
		for(int i=0;i<n;i++){
			L=max(L,arr[i]+arr[(i-1+n)%n]);
		}
		if(n==1){
			cout<<arr[0]<<'\n';
			continue;
		}
		if(n%2==0){
			cout<<L<<'\n';
			continue;
		}
		cout<<bs(L,R)<<'\n';
	}
}
