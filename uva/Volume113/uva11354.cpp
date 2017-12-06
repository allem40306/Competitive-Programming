#include <bits/stdc++.h>
using namespace std;
const int N=50010;
const int INF=1e9;
struct edge{
	int s,t,w;
}a[2*N];
struct edge2{
	int t,w;
	edge2(int t,int w):t(t),w(w){}
	edge2(){};
};

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int n,m,q,x,y,djs[N],depth[N],par[N][25],maxcost[N][25];
vector<edge2>v[N];
int query(int x){return (x==djs[x]?x:djs[x]=query(djs[x]));}

void init(){
	memset(par,-1,sizeof(par));
	memset(maxcost,-1,sizeof(maxcost));
	for(int i=0;i<N;i++){
		djs[i]=i;
		v[i].clear();
	}
}

void MST(){
	int fa,fb;
	for(int i=0;i<m;i++){
		fa=query(a[i].s),fb=query(a[i].t);
		if(fa!=fb){
			djs[fa]=fb;
			v[a[i].s].push_back(edge2(a[i].t,a[i].w));
			v[a[i].t].push_back(edge2(a[i].s,a[i].w));
		}
	}
}

void dfs(int s,int f,int d){
	depth[s]=d;
	par[s][0]=f;
	for(auto i:v[s]){
		if(i.t!=f){
			maxcost[i.t][0]=i.w;
			dfs(i.t,s,d+1);
		}
	}
}

void preprocess(){
	for(int i=1;i<=25;i++){
		for(int j=1;j<=n;j++){
			if(par[j][i-1]==-1||par[par[j][i-1]][i-1]==-1)continue;
			par[j][i]=par[par[j][i-1]][i-1];
			maxcost[j][i]=max(maxcost[j][i-1],maxcost[par[j][i-1]][i-1]);
		}
	}
}

void solve(int p,int q){
	if(depth[p]<depth[q])swap(p,q);
//    cout<<p<<'_'<<q<<'\n';
	int hibit,ans=-INF;
	for(hibit=1;(1<<hibit)<=depth[p];++hibit);--hibit;
	for(int i=hibit;i>=0;i--){
//        cout<<p<<' '<<i<<'\n';
		if(depth[p]-(1<<i)>=depth[q]){
			ans=max(ans,maxcost[p][i]);
			p=par[p][i];
		}
//		cout<<p<<' '<<q<<' '<<ans<<'\n';
	}
	if(p==q){
            cout<<ans<<'\n';
            return;
	}
	for(int i=hibit;i>=0;i--){
        if(par[p][i]==-1||par[p][i]==par[q][i])continue;
		ans=max(ans,maxcost[p][i]); p=par[p][i];
		ans=max(ans,maxcost[q][i]); q=par[q][i];
//		cout<<p<<' '<<q<<' '<<ans<<'\n';
	}
	ans=max(ans,maxcost[p][0]);
	ans=max(ans,maxcost[q][0]);
	cout<<ans<<'\n';
}

int main(){
//    freopen("test.out","w",stdout);
    cin.tie(NULL);
	bool b=0;
	while(cin>>n>>m){
		if(b)cout<<'\n'; b=1;
        init();
		for(int i=0;i<m;i++){
			cin>>a[i].s>>a[i].t>>a[i].w;
		}
		sort(a,a+m,cmp);
		MST();
		dfs(1,-1,0);
//		for(int i=1;i<=n;i++)cout<<par[i][0]<<' ';cout<<'\n';
		preprocess();
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>x>>y;
			solve(x,y);
		}
	}
}
