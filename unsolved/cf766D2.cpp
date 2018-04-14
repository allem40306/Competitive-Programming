#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,q,x,op[N],djs[N];
map<string,int>ma;
string s,r;
int f(int x){return x==djs[x]?x:x=f(djs[x]);}
void u(int x,int y){
	int fx=f(x),fy=f(y);
	djs[fx]=djs[fy];
	return;
}
void u2(int x,int y){
	int fx=f(x),fy=f(y);
	if(op[fx]!=-1)u(fy,op[fx]);
	if(op[fy]!=-1)u(fx,op[fy]);
	op[fx]=fy;
	op[fy]=fx;
	return;
}

int main(){
	cin>>n>>m>>q;
	memset(op,-1,sizeof(op));
	for(int i=0;i<N;i++)djs[i]=i;
	for(int i=1;i<=n;i++){
		cin>>s;
		ma[s]=i;
	}
	for(int i=0;i<m;i++){
		cin>>x>>s>>r;
		cout<<s<<':'<<ma[s]<<':'<<djs[ma[s]]<<':'<<op[djs[ma[s]]]<<endl;
		cout<<r<<':'<<ma[r]<<':'<<djs[ma[r]]<<':'<<op[djs[ma[r]]]<<endl;
		if(x==1){
			if(op[djs[ma[s]]]==djs[ma[r]])cout<<"NO\n";
			else{
				cout<<"YES\n";
				u(ma[s],ma[r]);
			}
		}else{
			if(djs[ma[s]]==djs[ma[r]]||(op[djs[ma[s]]]!=-1&&op[djs[ma[s]]]==op[djs[ma[r]]]))cout<<"NO\n";
			else{
				cout<<"YES\n";
				u2(ma[s],ma[r]);
			}
		}
		cout<<s<<':'<<ma[s]<<':'<<djs[ma[s]]<<':'<<op[djs[ma[s]]]<<endl;
		cout<<r<<':'<<ma[r]<<':'<<djs[ma[r]]<<':'<<op[djs[ma[r]]]<<endl;
	}
	for(int i=0;i<q;i++){
		cin>>s>>r;
		cout<<s<<':'<<ma[s]<<':'<<djs[ma[s]]<<':'<<op[djs[ma[s]]]<<endl;
		cout<<r<<':'<<ma[r]<<':'<<djs[ma[r]]<<':'<<op[djs[ma[r]]]<<endl;
		if(djs[ma[s]]==djs[ma[r]])cout<<"1\n";
		else if(op[djs[ma[s]]]==djs[ma[r]])cout<<"2\n";
		else cout<<"3\n";
	}
}
