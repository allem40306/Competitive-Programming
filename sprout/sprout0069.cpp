#include <iostream>
#include <algorithm>
using namespace std;
#define N 10005
long long t,ti,n,k,c[N];
bool f;
struct myhorse{
	long long a,b,r; //result
	bool operator<(const myhorse& b){
		if(r!=b.r)
			return r<b.r;
	}
}h[N];
bool ddd(long long d){
	long long i,j;
	for(i=0;i<n;i++){
		h[i].r=h[i].a+h[i].b*d;
	}
	sort(h,h+n);
	for(i=j=0;i<n&&j<n;){
		while(i<n&&h[i].r<=c[j])i++;
		if(i<n&&h[i].r>c[j]){i++;j++;}
	}
	if(j>=k)
		return f=1;
	return 0;
}
int main(){
	cin.tie(NULL);
	for(cin>>t;ti<t;ti++){
		cin>>n>>k;
		for(long long i=0;i<n;i++){
			cin>>h[i].a>>h[i].b;
		}
		for(long long i=0;i<n;i++){
			cin>>c[i];
		}
		sort(c,c+n);
		f=0; 
		int L=0,R=100000005,M;
		while(L!=R){
//			cout<<L<<' '<<R<<'\n';
			M=(L+R)>>1;
			if(ddd(M))
				R=M;
			else
				L=M+1;
		}
		if(f)
			cout<<L<<'\n';
		else
			cout<<-1<<'\n';
	}
}
