#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 3005
bool vis[N];
vector <int>v[N];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	}
}
int main(){
	cin.tie(NULL);
	int n,m,t,ti,i,x,y,ans;
	for(cin>>t,ti=0;ti<t;ti++){
		ans=0;
		for(i=0;i<N;i++)v[i].clear();
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=0;i<n;i++){
			if(!vis[i]){
				ans++;
				dfs(i);
			}
		}
		cout<<ans<<'\n';
	}
}
