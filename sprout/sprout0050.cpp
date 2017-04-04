#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 100005
vector<int>v[N];
int ans[N],t,n,i,x,y;
bool vis[N];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(vis[v[x][i]])continue;
		dfs(v[x][i]);
		ans[x]+=ans[v[x][i]];
	}
	ans[x]++;
	return;
}
void init(){
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++)
		v[i].clear();
}
int main(){
	for(cin>>t;i<t;i++){
		cin>>n;
		init(); 
		for(int j=1;j<n;j++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(0);
		for(int i=0;i<n;i++)
			printf("node %d: %d\n",i,ans[i]);
	}
}
