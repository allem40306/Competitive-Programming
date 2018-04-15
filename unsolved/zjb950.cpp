#include <bits/stdc++.h>
using namespace std;
const long long int N=1000000,Z=100005;

long long lower(long long int* a,int R,int v){
	int L=0,m;
	while(L!=R){
		m=(L+R)>>1;
		if(v>a[m])L=m+1;
		else R=m;
	}
	return a[L];
}

long long upper(long long int* a,int R,int v){
	int L=0,m;
	while(L!=R){
		m=(L+R)>>1;
		if(v<a[m])R=m-1;
		else L=m;
	}
	return a[L];
}

int main(){
	long long int n,x,y,dx,dy,z,q,a,b,np,v;//new point
	long long int qx[Z],qy[Z];
	cin>>n>>x>>y>>z;
	for(int i=0;i<z;i++){
		cin>>dx>>dy;
		qx[i]=dx*N+dy;
		qy[i]=dy*N+dx;
	}
	sort(qx,qx+z);
	sort(qy,qy+z);
	z--;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b;
		if(a==1){
			np=(x+b<=n?x+b:n);
			v=lower(qy,z,y*N+np);
			x=(v/N==y&&v>y*N+x?v%N-1:np);
		}else if(a==2){
			np=(x-b>0?x-b:1);
			v=upper(qy,z,y*N+np);
			x=(v/N==y&&v<y*N+x?v%N+1:np);
		}else if(a==3){
			np=(y+b<=n?y+b:n);
			v=lower(qx,z,x*N+np);
			y=(v/N==x&&v>x*N+y?v%N-1:np);
		}else{
			np=(y-b>0?y-b:1);
			v=upper(qx,z,x*N+np);
			y=(v/N==x&&v<x*N+y?v%N+1:np);
		}
		cout<<x<<' '<<y<<'\n';
	}
}

