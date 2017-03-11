#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define N 100005 
struct Node{
    int t;
    vector<int>v;
}t[N];
bool vis[N],h[N];
void dfs(int x){
//	cout<<x<<' '<<t[x].t<<endl;
	vis[x]=1;
	for(int i=0;i<t[x].v.size();i++){
		dfs(t[x].v[i]);
		t[x].t+=t[t[x].v[i]].t;
//		cout<<x<<' '<<t[x].t<<endl;
	}
	return;
}
void init(){
	memset(vis,0,sizeof(vis));
	memset(h,1,sizeof(h));
	for(int i=0;i<N;i++){
		t[i].t=1;
		t[i].v.clear();
	}
	return;
}
int tt,ti,n,m,q,x,y;
int main(){
	for(cin>>tt;ti<tt;ti++){
		init();
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			t[x].v.push_back(y);
			h[y]=0;
		}
		for(int i=1;i<=n;i++)
			if(h[i]&&!vis[i])
				dfs(i);
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>x;
			cout<<t[x].t<<endl;
		}
	}
}
