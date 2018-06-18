#include <bits/stdc++.h>
using namespace std;
const int N=100000+5;
vector<int>va[N],vb[N];
queue<int>q;
int la[N],lb[N];//loc

void init(){
	memset(la,-1,sizeof(la));
	memset(lb,-1,sizeof(lb));
	for(int i=0;i<N;i++){
		va[i].clear();
		vb[i].clear();
	}
}

inline void qinit(int i){
	while(!q.empty()){
		q.pop();
	}
	q.push(i);
}

int main(){
	int t,ti=0,n,ma,mb,k,u,v,a,b,qq;
	for(cin>>t;ti<t;ti++){
		cin>>n>>ma>>mb>>k>>a>>b;
		init();
		qinit(a);
		for(int i=0;i<ma;i++){
			cin>>u>>v;
			va[u].push_back(v); 
		}
		la[a]=0;
		while(!q.empty()){
			qq=q.front();q.pop();
			for(auto i:va[qq]){
				if(la[i]==-1){
					la[i]=la[qq]+1;
					q.push(i);
				}
			}
		}
		qinit(b);
		for(int i=0;i<mb;i++){
			cin>>u>>v;
			vb[u].push_back(v); 
		}
		lb[b]=0;
		while(!q.empty()){
			qq=q.front();q.pop();
			for(auto i:vb[qq]){
				if(lb[i]==-1){
					lb[i]=lb[qq]+1;
					q.push(i);
				}
			}
		}
		bool yes=0;
		for(int i=0;i<n;i++){
//			cout<<la[i]<<' '<<lb[i]<<'\n';
			if(la[i]!=-1&&lb[i]!=-1&&la[i]<=k&&lb[i]<=k){
				yes=1;
			}
		}
		cout<<(yes?"Yes.\n":"No.\n");
	}
}
