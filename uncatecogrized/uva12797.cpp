#include <iostream>
#include <cstring>
using namespace std;
int n,ans=100000;
bool used[200],vis[105][105];
string s[105];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
void dfs(int x,int y,int d){
	cout<<x<<' '<<y<<' '<<d<<'\n';
	if(x==n-1&&y==n-1){
		ans=(ans>d?d:ans);
		return;
	}
	for(int i=0;i<8;i++){
		if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<n&&!vis[x+dx[i]][y+dy[i]]&&!used[s[x+dx[i]][y+dy[i]]+32]&&!used[s[x+dx[i]][y+dy[i]]-32]){
			vis[x+dx[i]][y+dy[i]]=used[s[x+dx[i]][y+dy[i]]]=1;
			dfs(x+dx[i],y+dy[i],d+1);
			vis[x+dx[i]][y+dy[i]]=used[s[x+dx[i]][y+dy[i]]]=0;
		}
	}
	return;
}

int main() {
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		memset(used,0,sizeof(used));
		memset(vis,0,sizeof(vis));
		used[s[0][0]]=1;
		dfs(0,0,1);
		cout<<(ans==100000?-1:ans)<<'\n';
	}
}
