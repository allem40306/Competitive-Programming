#include <bits/stdc++.h>
using namespace std;
const int N=30;
bool adj[N][N];

void dfs(int s,int t,int step){
	
}

int main(){
	char ch,s,t;
	int v;
	while(cin>>ch,ch!='#'){
		memset(adj,false,sizeof(adj));
		s=ch;
		while(cin>>ch){
			if(ch==':')continue;
			if(ch==':'){
				cin>>s;
				continue;
			}
			if(ch=='.')break;
			adj[s-'A'][ch-'A']=1;
		}
		cin>>s>>t>>v;
		dfs(s,t,v);
	}
}
