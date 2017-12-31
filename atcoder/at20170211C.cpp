#include <bits/stdc++.h>
using namespace std;
#define N 10
vector<int>v[N];
int n,m,x,y;
bool vis[N];

int solve(int a,int b){
//	cout<<a<<endl;
	if(b==n)return 1;
	int ans=0;
	for(int i=0,j=v[a].size();i<j;i++){
		if(!vis[v[a][i]]){
			vis[v[a][i]]=1;
			ans+=solve(v[a][i],b+1);
			vis[v[a][i]]=0;
		}
	}
	return ans;
}

int main(){
	memset(vis,0,sizeof(0));
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vis[1]=1;
	cout<<solve(1,1)<<endl;
}
