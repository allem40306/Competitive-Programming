#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,m,q,x,op[N],djs[N],ss,rr;
map<string,int>ma;
string s,r;
int f(int x){return x==djs[x]?x:x=f(djs[x]);}
void u(int x,int y){
	int fx=f(x),fy=f(y);
	djs[fx]=djs[fy];
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
		ss=ma[s];rr=ma[r];
		cout<<s<<':'<<ss<<':'<<djs[ss]<<':'<<op[djs[ss]]<<endl;
		cout<<r<<':'<<rr<<':'<<djs[rr]<<':'<<op[djs[rr]]<<endl;
		if(x==1){
			if(op[djs[ss]]==djs[rr])cout<<"NO\n";
			else{
				cout<<"YES\n";
				u(ss,rr);
			}
		}else{
			if(djs[ss]==djs[rr]||(op[djs[ss]]!=-1&&op[djs[ss]]==op[djs[rr]]))cout<<"NO\n";
			else{
				cout<<"YES\n";
				
			}
		}
		cout<<s<<':'<<ss<<':'<<djs[ss]<<':'<<op[djs[ss]]<<endl;
		cout<<r<<':'<<rr<<':'<<djs[rr]<<':'<<op[djs[rr]]<<endl;
	}
	for(int i=0;i<q;i++){
		cin>>s>>r;
		cout<<s<<':'<<ss<<':'<<djs[ss]<<':'<<op[djs[ss]]<<endl;
		cout<<r<<':'<<rr<<':'<<djs[rr]<<':'<<op[djs[rr]]<<endl;
		if(djs[ss]==djs[rr])cout<<"1\n";
		else if(op[djs[ss]]==djs[rr])cout<<"2\n";
		else cout<<"3\n";
	}
}
