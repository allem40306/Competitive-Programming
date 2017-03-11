#include <bits/stdc++.h>
using namespace std;
#define N 1005
int t,ti,n,ni,a[N],b[N],x,xi,ans,i;
bool r[N];
vector<int>v[N];
void init(){
	memset(b,0,sizeof(b));
	memset(r,0,sizeof(r));
	for(int i=0;i<N;i++)
		v[i].clear();
	ans=0;
}
void dfs(int x,int d){
	b[x]=max(b[x],a[x]+d);
//	cout<<x<<' '<<b[x]<<endl;
	for(int len=v[x].size(),i=0;i<len;i++)
		dfs(v[x][i],b[x]);
}
int main(){
	for(cin>>t;ti<t;ti++){
		init();
		cin>>n;
		for(ni=1;ni<=n;ni++){
			cin>>a[ni]>>xi;
			while(xi--){
				cin>>x;
				r[x]=1;
				v[ni].push_back(x);
			}
		}
		for(i=1;i<=n;i++)
			if(!r[i])dfs(i,0);
		for(i=1;i<=n;i++)
			ans=max(ans,b[i]);
		cout<<ans<<endl;
	}
}
