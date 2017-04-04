#include <bits/stdc++.h>
using namespace std;
#define N 100005
int ans[N];
bool vis[N];
vector<int>ve[N];
void dfs(int v,int d,int c){
//	cout<<v<<' '<<d<<' '<<c<<'\n'; 
	vis[v]=1;
	ans[v]=c;
	if(!d)return;
	for(int i=0;i<ve[v].size();i++){
		if(!vis[ve[v][i]]){
			dfs(ve[v][i],d-1,c);
		}
	}
}
int main(){
	cin.tie(NULL);
	int n,m,q,a,b,v,d,c;
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<m;i++){
		cin>>a>>b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>v>>d>>c;
		memset(vis,0,sizeof(vis));
		dfs(v,d,c);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<'\n';
}
