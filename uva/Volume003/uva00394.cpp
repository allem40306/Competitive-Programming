#include <bits/stdc++.h>
using namespace std;

struct node{
	int b,d,c[15],L[15],U[15];
};

int main(){
	int n,r,t;
	string s,o;
	node x;
	map<string,node>ma;
	cin>>n>>r;
	for(int i=0;i<n;i++){
		cin>>s;
		cin>>x.b>>t>>x.d;
		x.c[x.d]=t;
		for(int j=1;j<=x.d;j++){
			cin>>x.L[j]>>x.U[j];
		}
		for(int j=x.d-1;j>0;j--){
			x.c[j]=x.c[j+1]*(x.U[j+1]-x.L[j+1]+1);
		}
		x.c[0]=x.b;
		for(int i=1;i<=x.d;i++){
			x.c[0]-=x.c[i]*x.L[i];
		}
		ma[s]=x;
	}
	int v;
	cin>>ws;
	for(int i=0;i<r;i++){
		getline(cin,s);
		stringstream ss(s);
		ss>>s;
		cout<<s;
		x=ma[s];
		v=x.c[0];
		o="[";
		for(int i=1;ss>>t;i++){
			cout<<o<<t;
			o=", ";
			v+=x.c[i]*t;
		}
		cout<<"] = "<<v<<'\n';
	}
}
