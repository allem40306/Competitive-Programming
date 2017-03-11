#include <bits/stdc++.h>
using namespace std;
#define N 200005
int lenp,lenr,a[N];
bool eat[N];
string p,r;
bool ddd(int x){
	int i,j;
	memset(eat,0,sizeof(eat));
	for(i=0;i<x;i++)
		eat[a[i]]=1;
	for(i=j=0;j<lenr;j++){
		while(i<lenp&&(eat[i]||p[i]!=r[j]))i++;
//		cout<<i<<endl;
		if(i==lenp)return 0;
		i++;
	}
	return 1;
}
int main(){
	cin>>p>>r;
	lenp=p.size(),lenr=r.size();
	for(int i=0;i<lenp;i++){
		cin>>a[i];
		a[i]--;
	}
	int L=0,M,R=lenp+1;
	while(L+1<R){
		M=(L+R)>>1;
		if(ddd(M))L=M;
		else  R=M;
//		cout<<L<<' '<<R<<endl;  
	}
	cout<<L<<endl;
}
