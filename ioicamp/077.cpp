#include <bits/stdc++.h>
using namespace std;
#define N 100005
long long t,ti,n,ans,a[N];
vector <int> v[N];
void init(){
	for(int i=0;i<N;i++)
		v[i].clear();
	return;
}

int subtree(int i){
	int k=0;
	for(int j=0;j<v[i].size();j++)
		k+=v[i][j]=subtree(v[i][j]);
	for(int j=0;j<v[i].size();j++)
		a[i]+=(k+2-v[i][j])*v[i][j]; 
	return k+1;
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int i,x;
	for(cin>>t;ti<t;ti++){
		memset(a,0,sizeof(a));
		cin>>n;
		init();
		for(i=2;i<=n;i++){
			cin>>x;
			v[x].push_back(i);
		}
		subtree(1);
		for(int i=1;i<=n;i++){
			if(i>1)cout<<' ';
			cout<<a[i]+1;
		}
		cout<<endl;
	}
}
