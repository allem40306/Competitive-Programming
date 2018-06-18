#include <bits/stdc++.h>
using namespace std;
const int N=25;
int n,s,t;
bool vis[N],vis2[N][N],adj[N][N];
double arr[N][N],ans[N];

double dfs(int p){
	if(vis[p]){
		return ans[p];
	}
	double x=1;
	for(int i=1;i<=n;i++){
		if(i!=p&&!vis2[p][i]&&adj[p][i]){
//			cout<<p<<' '<<i<<'\n';
			vis2[p][i]=vis2[i][p]=1;
			if(vis[i])x*=(1-arr[p][i]*ans[i]);
			else x*=(1-arr[p][i]*dfs(i));
		}
	}
	return ans[p]=1-x;
}

int main(){
	while(cin>>n){
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		memset(adj,0,sizeof(adj));
		for(int i=0;i<n;i++){
			ans[i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>arr[i][j];
				if(arr[i][j])adj[i][j]=1;
			}
		}
		cin>>s>>t;
		vis[t]=1;
		ans[t]=1;
		dfs(s);
		cout<<fixed<<setprecision(5)<<ans[s]<<'\n';
	}
} 
