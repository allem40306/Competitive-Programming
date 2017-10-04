#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
int main(){
	int n,s,t,ss,tt,x,y,z,q,a,b;
	int dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
	map<int,int> m;
	cin>>n>>s>>t>>z;
	for(int i=0;i<z;i++){
		cin>>x>>y;
		m.insert(pair<int,int>(x*N+y,1));
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b;
		while(b--){
			ss=s+dx[a];tt=t+dy[a];
			if((!(ss&&tt&&ss<=n&&tt<=n))||m.find(ss*N+tt)!=m.end())break;
			s=ss;t=tt;
		}
		cout<<s<<' '<<t<<'\n';
	}
}
