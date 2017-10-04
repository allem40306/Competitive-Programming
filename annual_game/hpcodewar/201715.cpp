#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define N 5005
int n,m,p,pp[N],ans;
bool vis[N]={};
vector<int>v[N];
void dfs(int i){
	ans+=pp[i];
	vis[i]=1;
	for(int j=0;j<v[i].size();j++){
		if(!vis[v[i][j]])dfs(v[i][j]);
	}
}
int main(){
	string s,a,b;
	map <string,int> ma;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s>>p;
		ma[s]=i;
		pp[i]=p;
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[ma[b]].push_back(ma[a]);
	}
	cin>>s;
	ans=0;
	dfs(ma[s]);
	cout<<ans<<'\n';
}
