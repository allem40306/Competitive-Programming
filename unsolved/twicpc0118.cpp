#include <bits/stdc++.h>
using namespace std;
#define N 20
#define M 10
#define ULL unsigned long long
ULL a,b,arr[N][M]={1,1,1,1,1,1,1,1,1,1,9},sun[N]={9};

void bulid(ULL x){
	if(x==N-1)return;
	ULL i=arr[x-1][0],j;
	arr[x+1][0]=arr[x][0];
	for(ULL y=1;y<M;y++){
		arr[x][y]=arr[x][y-1]-arr[x-1][y-1];
		arr[x+1][0]+=arr[x][y];
	}
	bulid(x+1);
}

ULL f(ULL a,ULL b,ULL c){
	if(!a)return c;
	f(a/10,b+1,)
}

int main(){
	bulid(1);
	cin>>a>>b;
	cout<<f(a,0,0)-f(b,0,0)+1<<endl;
}
