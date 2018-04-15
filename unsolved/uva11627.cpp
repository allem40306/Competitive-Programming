#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
int n,ss,s[N];
double vh,x[N/10],y[N/10],w;

bool ok(int xx){
	double L=x[0],R=x[0]+w;
	for(int i=1;i<n;i++){
        double d=y[i]-y[i-1];
        double t=d/s[xx];
		L-=t*vh;
		R+=t*vh;
		L=max(L,x[i]);
		R=min(R,x[i]+w);
//		cout<<L<<'+'<<R<<'\n';
		if(L>R&&fabs(L-R)>1e-9)return 0;
	}
	return 1;
}

int main(){
//	freopen("11627.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>w>>vh>>n;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		cin>>ss;
		for(int i=0;i<ss;i++){
			cin>>s[i];
		}
		sort(s,s+ss);
		if(!ok(0)){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		int L=0,R=ss-1,M;
		while(L!=R){
			M=(L+R+1)>>1;
			if(ok(M))L=M;
			else R=M-1;
		}
		cout<<s[L]<<'\n';
	}
}
