#include <iostream>
using namespace std;
int a[1000005],arr[1005][1005];
int f(int L,int R,int x){
	int ans=0,ansi=L,i;
	for(int a=L;a<=R;a++){
		i=GetVal(x,a);
//		i=arr[x][a];
		if(i>ans){
			ansi=a;
			ans=i;
		}
	}
	return ansi;
}
void sear(int L,int R,int LL,int RR){
	int M=(L+R)>>1;
//	cout<<L<<' '<<M<<' '<<R<<' '<<LL<<' '<<RR<<'\n';
	if(!a[M]){
		a[M]=f(LL,RR,M);
//		cout<<a[M]<<'\n';
	}
	if(L==R)return;
	sear(L,M,LL,a[M]-1);
	sear(M+1,R,a[M]+1,RR);
}
void solve(int N,int M){
	sear(1,N,1,M);
	for(int i=1;i<=N;i++)
		Report(a[i]);
//		cout<<a[i]<<'\n';
}
//int main(){
//	cin.tie(NULL);
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cin>>arr[i][j]; 
//	solve(n,m);
//}
