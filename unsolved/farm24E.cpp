#include <bits/stdc++.h>
using namespace std;
#define N 100
long long n,a[N],p[2],sum=0;
bool vis[N],pp[2];
void solve(int x,int r){
	for(int i=2*n-1;i>=0;i--){
		if(vis[i]||(p[x]+a[i])*3>sum*2)continue;
		p[x]+=a[i];
		vis[i]=1;
		solve(!x,r+1);
		return;
	}
	if(r!=2*n)pp[x]=1;
	return;	
}

int main(){
	cin>>n;
	for(int i=0;i<2*n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+2*n);
	solve(0,0);
	if(pp[0])cout<<"T_T\n";
	else if(pp[1])cout<<">_<\n";
	else cout<<p[0]-p[1]<<"\n";
}
