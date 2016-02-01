#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
#define M 200005
#define gor(a,b) for(a=0;a<b;a++)

int main() {
	int t,ti=0; 
	for(cin>>t;ti<t;ti++){
		int n,m,q,i;
		cin>>n>>m>>q;
		int a,b,u,x,y,mo[M]; //mo(ney)
		vector <int> f[M];
		gor(i,m){
			cin>>a>>b;
			f[a].push_back(b);
			f[b].push_back(a);
		}
		gor(i,q){
		cin>>u>>x>>y;
		mo[u]+=x;
		gor(i,n)mo[i]+=y+(x-y)*(u==i);
		stack <int> st;
		while(!f[u].empty){
			int p=f[u].back;
			mo[p]-=y;
			f[u].pop_back;
			st.push(p);
		}
		while(!st.empty()){
			f[u].push_back(st.top());
			st.pop();
		}
		}
		gor(i,n)printf("%d ",m[i]);
		printf("\n");
	}
	
}
