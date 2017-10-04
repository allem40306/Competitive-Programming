#include <bits/stdc++.h>
using namespace std;
int n,nn,m,k,a1,a2;
array<int,30>go;
int rou(int pos,int dir,int step){
	for(int i=0;i<step;i++){
		do{
			pos=(pos+dir+n-1)%n+1;
		}while(go[pos]);
	}
	return pos;
}

int main(){
	while(cin>>n>>k>>m,n||k||m){
		go.fill(0);
		nn=n;
		a1=n;
		a2=1;
		while(nn){
			a1=rou(a1,1,k);
			a2=rou(a2,-1,m);
			if(a1==a2){
				cout<<setw(3)<<a1;
				nn-=1;	
			}else{
				cout<<setw(3)<<a1<<setw(3)<<a2;
				nn-=2;
			}
			if(nn){
				cout<<',';
			}
			go[a1]=go[a2]=1;
		}
		cout<<'\n';
	}
}
