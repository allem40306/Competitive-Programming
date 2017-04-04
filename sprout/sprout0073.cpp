#include <iostream>
using namespace std;
#define N 100005
int t,ti,n,m,a[N];
bool ddd(int d){
	int x=m,y;
	for(int i=0;i<n;){
		if(!x)return 0;
		y=0;
		while(i<n&&y+a[i]<=d){
			y+=a[i];
			i++;
		}
		x--;
		if(!y)return 0;
	}
	return 1;
}
int main(){
	cin.tie(NULL);
	for(cin>>t;ti<t;ti++){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int L=1,R=1000000005,M;
		while(L!=R){
//			cout<<L<<' '<<R<<'\n';
			M=(L+R)>>1;
			if(ddd(M))
				R=M;
			else
				L=M+1;
		}
		cout<<L<<'\n';
	}
}
