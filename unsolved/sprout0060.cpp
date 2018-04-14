#include <iostream>
using namespace std;
int a,b,c,d,t,m,s;
bool dd(int t,int td){
	int nd=t*a,nm=m,nt=t,ut;
	while(nd<td&&nt>0){
		ut=(nm>=c?0:d/(c-nm)+(d/(c%nm)>0));
//		cout<<nd<<' '<<nt<<' '<<ut<<'\n';
		if(b<=a*(ut+1)||ut+1>nt)break;
		nd=nd-a*(ut+1)+b;
		nt-=(ut+1);
	}
//	cout<<nd<<'d'<<td<<'\n';
	return nd>=td;
}
int dl;
int ddd(int t){
	int L=1,R=t+1,M;
	while(L!=R){
//		cout<<L<<'t'<<R<<'\n';
		M=(L+R>>1);
		if(!dd(t,M))
			R=M;
		else
			L=M+1;
	}
	return L;
}
int main(){
	cin.tie(NULL);
	cin>>a>>b>>c>>d>>m>>s>>t;
	int L=0,R=s,M,ct=0,ansd=0;
	while(L!=R){
		cout<<L<<'d'<<R<<'\n';
		M=(L+R)>>1;
		ct=ddd(M);
		if(ct<=t){
			ansd=max(M,ansd);
			L=M+1;
		}
		else
			R=M;
	}
	if(L==s){
		cout<<"Yes\n";
		cout<<ct<<'\n';
	}
	else{
		cout<<"No\n";
		cout<<ansd<<'\n';
	}
}
