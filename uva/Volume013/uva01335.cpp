#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int arr[N],n,al[N],ar[N];

bool ok(int x){
	int L=arr[0],R=x-L;
	al[0]=L; ar[0]=0;
	for(int i=0;i<n;i++){
		if(i&1){
			al[i]=min(L-al[i],arr[i]);
			ar[i]=arr[i]-al[i];
		}else{
			ar[i]=min(R-ar[i],arr[i]);
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
		cout<<bs(1,3*N)<<'\n';
	}
}
