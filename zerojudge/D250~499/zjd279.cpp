#include <bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>v[N];
bool vis[N];
int ans;
void dfs(int p){
	for(int i=0;i<v[p].size();i++){
		if(vis[v[p][i]])continue;
		vis[v[p][i]]=1;
		ans--;
		dfs(v[p][i]);
	}
}

int main(){
	int n,x,y;
	while(cin>>n,n){
		for(int i=0;i<N;i++){
			v[i].clear();
		}
		while(cin>>x,x){
			while(cin>>y,y){
				v[x].push_back(y);
			}
		}
		cin>>x;
		while(x--){
			memset(vis,0,sizeof(vis));
			ans=n;
			cin>>y;
			dfs(y);
			cout<<ans;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					cout<<' '<<i;
				}
			}
			cout<<'\n';
		}
	}
}
