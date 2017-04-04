#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 100005
int group[N];
bool vis[N];
vector <int>v[N];
bool dfs(int x){
	vis[x]=1;
	if(group[x]==-1)group[x]=0;
	for(int i=0;i<v[x].size();i++){
		if(group[v[x][i]]!=-1){
			if(group[v[x][i]]==group[x])
				return 0;
		}else
			group[v[x][i]]=1-group[x];
		if(!vis[v[x][i]]&&!dfs(v[x][i]))
			return 0;
	}
	return 1;
}
int main(){
	cin.tie(NULL);
	int n,m,i,x,y;
	bool ans;
	for(;cin>>n,n;){
		cin>>m;
		ans=1;
		for(i=0;i<N;i++)v[i].clear();
		memset(vis,0,sizeof(vis));
		memset(group,-1,sizeof(group));
		for(i=0;i<m;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=0;ans&&i<n;i++){
			if(!vis[i]){
				ans=dfs(i);
			}
		}
		if(ans)cout<<"NORMAL.\n";
		else cout<<"RAINBOW.\n";
	}
}
