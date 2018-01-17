#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int ansx[N],ansy[N];
struct node{
	int a,b,id;
	bool operator <(const node&x)const{
		return b<x.b;
	}
}nx[N],ny[N];
bool usex[N],usey[N];
int n,px,py;
bool ok(){
	memset(usex,0,sizeof(usex));
	memset(usey,0,sizeof(usey));
	for(int i=0;i<n;i++){
		px=py=-1;
//		cout<<nx[i].a<<'='<<nx[i].b<<'\n';
//		cout<<ny[i].a<<'='<<ny[i].b<<'\n';
		for(int j=nx[i].a;j<=nx[i].b;j++){
			if(!usex[j]){
				px=j;
				usex[j]=1;
				break;
			}
		}
		for(int j=ny[i].a;j<=ny[i].b;j++){
			if(!usey[j]){
				py=j;
				usey[j]=1;
				break;
			}
		}
		if(px==-1||py==-1)return 0;
		ansx[nx[i].id]=px;
		ansy[ny[i].id]=py;
	}
	return 1;
}
int main(){
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>nx[i].a>>ny[i].a>>nx[i].b>>ny[i].b;
			nx[i].id=ny[i].id=i;
		}
		sort(nx,nx+n);
		sort(ny,ny+n);
		if(ok()){
			for(int i=0;i<n;i++){
				cout<<ansx[i]<<' '<<ansy[i]<<'\n';
			}
		}else{
			cout<<"IMPOSSIBLE\n";
		}
	}
} 
