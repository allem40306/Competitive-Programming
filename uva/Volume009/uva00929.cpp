#include <bits/stdc++.h>
using namespace std;
const int N=1005;
struct node{
	int x,y,d;
	node(){};
	node(int x,int y,int d):x(x),y(y),d(d){}
	bool operator <(const node&b)const{
		return d>b.d;
	}
};
int main(){
	static int t,m,n,a[N][N],dp[N][N],xx,yy;
	int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
	priority_queue<node>pq;
	node k;
	cin>>t;
	while(t--){
		memset(dp,0x1f,sizeof(dp));
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		dp[0][0]=a[0][0];
		pq.push(node(0,0,dp[0][0]));
		while(!pq.empty()){
			k=pq.top(); pq.pop();
			for(int i=0;i<4;i++){
				xx=k.x+dx[i];
				yy=k.y+dy[i];
				if(xx<0||xx>=n||yy<0||yy>=m)continue;
				if(dp[xx][yy]>k.d+a[xx][yy]){
					dp[xx][yy]=k.d+a[xx][yy];
//					cout<<xx<<' '<<yy<<' '<<dp[xx][yy]<<'\n';
					pq.push(node(xx,yy,dp[xx][yy]));
				}
			}	
		}
		cout<<dp[n-1][m-1]<<'\n';
	}
}
