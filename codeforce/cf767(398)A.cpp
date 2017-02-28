#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,br;
bool vis[N]={},f;
int main(){
	cin>>n;
	br=n;
	for(int i=0;i<n;i++){
		f=0;
		cin>>m;
		vis[m]=1;
		while(vis[br]&&br){
			if(f)cout<<' ';
			f=1;
			cout<<br--;
		}
		cout<<endl;
	}
}
