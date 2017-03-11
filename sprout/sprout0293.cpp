#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define N 100005 
struct Node{
    int t,ans,nc;
    vector<int>v;
    Node():t(){}
}t[N];
bool vis[N],h[N];
void dfs(int x){
//	cout<<x<<' '<<t[x].t<<endl;
	vis[x]=1;
	for(int i=0;i<t[x].v.size();i++){
		if(vis[t[x].v[i]])continue; 
		dfs(t[x].v[i]);
		t[x].t+=t[t[x].v[i]].t;
		t[x].nc-=t[t[x].v[i]].t;
		t[x].ans=max(t[x].ans,t[t[x].v[i]].t);
	}
	t[x].ans=max(t[x].ans,t[x].nc);
//	cout<<x<<' '<<t[x].t<<' '<<t[x].ans<<endl;
	return;
}
int tt,ti,n,x,y,ans;
void init(int n){
	ans=0;
	memset(vis,0,sizeof(vis));
	memset(h,1,sizeof(h));
	for(int i=0;i<N;i++){
		t[i].ans=0;
		t[i].nc=n-1;
		t[i].t=1;
		t[i].v.clear();
	}
	return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	for(cin>>tt;ti<tt;ti++){
		cin>>n;
		init(n);
		for(int i=0;i<n-1;i++){
			cin>>x>>y;
			t[x].v.push_back(y);
			t[y].v.push_back(x);
			h[y]=0;
		}
		dfs(0);
		for(int i=0;i<n;i++)
			if(t[ans].ans>t[i].ans)
				ans=i;
		cout<<ans<<'\n';
	}
}
