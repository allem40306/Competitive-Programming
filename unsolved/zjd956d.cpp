#include <bits/stdc++.h>
using namespace std;
#define N 100000
int arr[N][2];
vector<int> x[N],y[N];
void bfsx(int i,int s){
	cout<<i<<' '<<s<<endl;
	arr[s][1]=i;
	int lens=x[i].size();
	for(int j=0;j<lens;j++)
		bfsx(i+1,x[i][j]);
}
void bfsy(int i,int s){
	arr[s][1]=i;
	int lens=y[i].size();
	for(int j=0;j<lens;j++)
		bfsx(i+1,y[i][j]);
}
bool ddd(int k){
	for(int i=0;i<N;i++){
		if(arr[i][0]&&arr[i][1]&&max(arr[i][0],arr[i][1])<=k)
			return 1;
	}
	return 0;
}
int main(){
	int t,ti=0,n,ma,mb,k,a,b,u,v;
	for(cin>>t;ti<t;ti++){
		cin>>n>>ma>>mb>>k>>a>>b;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<ma;i++){
			cin>>u>>v;
			x[u].push_back(v);	
		}for(int i=0;i<mb;i++){
			cin>>u>>v;
			y[u].push_back(v);
		}bfsx(a,1);bfsy(b,1);
		if(ddd(k))cout<<"Yes.\n";
		else cout<<"No.\n";
	}
}
